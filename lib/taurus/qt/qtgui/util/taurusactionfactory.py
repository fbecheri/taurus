#!/usr/bin/env python

#############################################################################
##
## This file is part of Taurus, a Tango User Interface Library
## 
## http://www.tango-controls.org/static/taurus/latest/doc/html/index.html
##
## Copyright 2011 CELLS / ALBA Synchrotron, Bellaterra, Spain
## 
## Taurus is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
## 
## Taurus is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
## 
## You should have received a copy of the GNU Lesser General Public License
## along with Taurus.  If not, see <http://www.gnu.org/licenses/>.
##
#############################################################################

"""This module is designed to provide a factory class for taurus Qt actions """

__all__ = ["ActionFactory"]

__docformat__ = 'restructuredtext'

import os
import xml.dom.minidom

from PyQt4 import Qt
import taurus.core.util

import taurusaction

class ActionFactory(taurus.core.util.Singleton, taurus.core.util.Logger):
    """A Singleton class designed to provide Action related objects."""

    def __init__(self):
        """ Initialization. Nothing to be done here for now."""
        pass

    def init(self, *args):
        """Singleton instance initialization."""
        self.call__init__(taurus.core.util.Logger,'ActionFactory')
        self.actions = self.__getActions()
        self.menus = self.__getMenus()
    
    def __getClasses(self, super_class):
        ret = {}
        klass_type = type(super_class)
        for name in dir(taurusaction):
            klass = getattr(taurusaction, name)
            if klass == super_class:
                continue
            if (type(klass) == klass_type and issubclass(klass, super_class)):
                ret[klass.menuID] = klass
        return ret
    
    def __getActions(self):
        """Calculates the map of existing action classes"""
        return self.__getClasses(taurusaction.TaurusAction)

    def __getMenus(self):
        """Calculates the map of existing menu classes""" 
        return self.__getClasses(taurusaction.TaurusMenu)

    def getActions(self):
        return self.actions
    
    def getMenus(self):
        return self.menus

    def getNewAction(self, widget, id):
        klass = self.actions.get(id)
        if klass is None:
            return None
        return klass(widget)

    def getNewMenu(self, widget, data):
        doc = xml.dom.minidom.parseString(data)
        m_node = doc.childNodes[0]
        return self.buildMenu(widget, m_node)
    
    def buildAction(self, widget, a_node):
        if not a_node.hasAttribute('class'):
            return None
        
        id = a_node.getAttribute('class')
        action = self.getNewAction(widget, id)
        
        # if node has alternative label, display it instead
        if a_node.hasAttribute('label'):
            action.setText(a_node.getAttribute('label'))
            
        if a_node.hasAttribute('checkable'):
            action.setCheckable(bool(a_node.getAttribute('checkable')))
        
        if a_node.hasAttribute('icon'):
            icon = a_node.getAttribute('icon')
            #TODO
            #action.setIcon(icon)
        return action
    
    def buildMenu(self, widget, m_node):
        menu = None 
        if m_node.hasAttribute('class'):
            klass = self.menus.get(m_node.getAttribute('class'))
            if klass is None:
                return None
            menu = klass(widget)
        else:
            menu = taurusaction.TaurusMenu(widget)
            menu.buildFromXML(m_node)
        return menu
            