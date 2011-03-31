//=============================================================================
//
// file :        Controller.h
//
// description : Include for the Controller class.
//
// project :	Device Pool Generic Controller
//
// $Author:  $
//
// $Revision:  $
//
// $Log:  $
//
// copyleft :    European Synchrotron Radiation Facility
//               BP 220, Grenoble 38043
//               FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================
#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <tango.h>
//using namespace Tango;

/**
 * @author	$Author:  $
 * @version	$Revision:  $
 */

 //	Add your own constants definitions here.
 //-----------------------------------------------


namespace Controller_ns
{

/**
 * Class Description:
 * A Controller Tango device which is the Tango API for the Device Pool generic controller
 */

/*
 *	Device States Description:
*  Tango::ON :      Controller is ready
*  Tango::FAULT :
*  Tango::ALARM :
*  Tango::MOVING :
 */


class Controller: public Tango::Device_4Impl
{
public :
    //	Add your own data members here
    //-----------------------------------------


    //	Here is the Start of the automatic code generation part
    //-------------------------------------------------------------	
/**
 *	@name attributes
 *	Attributs member data.
 */
//@{
        Tango::DevString	*attr_Elements_read;
//@}

/**
 *	@name Device properties
 *	Device properties member data.
 */
//@{
//@}

/**@name Constructors
 * Miscellaneous constructors */
//@{
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
    Controller(Tango::DeviceClass *cl,string &s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
    Controller(Tango::DeviceClass *cl,const char *s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device name
 *	@param d	Device description.
 */
    Controller(Tango::DeviceClass *cl,const char *s,const char *d);
//@}

/**@name Destructor
 * Only one desctructor is defined for this class */
//@{
/**
 * The object desctructor.
 */	
    ~Controller() {delete_device();};
/**
 *	will be called at device destruction or at init command.
 */
    void delete_device();
//@}

    
/**@name Miscellaneous methods */
//@{
/**
 *	Initialize the device
 */
    virtual void init_device();
/**
 *	Always executed method befor execution command method.
 */
    virtual void always_executed_hook();

//@}

/**
 * @name Controller methods prototypes
 */

//@{
/**
 *	Hardware acquisition for attributes.
 */
    virtual void read_attr_hardware(vector<long> &attr_list);
/**
 *	Extract real attribute values for Elements acquisition result.
 */
    virtual void read_Elements(Tango::Attribute &attr);
/**
 *	Read/Write allowed for Elements attribute.
 */
    virtual bool is_Elements_allowed(Tango::AttReqType type);
/**
 *	Execution allowed for AddElement command.
 */
    virtual bool is_AddElement_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DeleteElement command.
 */
    virtual bool is_DeleteElement_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for Send command.
 */
    virtual bool is_Send_allowed(const CORBA::Any &any);
/**
 * adds a new axis to the controller. This will translate in creating a new tango device of the
 *	class this controller type is.
 *	@param	argin	arg[0] - axis number (starting at 1)\narg[1] - element name\narg[2] - (optional) device name
 *	@exception DevFailed
 */
    void	add_element(const Tango::DevVarStringArray *);
/**
 * Removes the axis given as parameter for this controller
 *	@param	argin	the axis number or element name or device name
 *	@exception DevFailed
 */
    void	delete_element(Tango::DevString);
/**
 * Sends a string of characters to the controller
 *	@param	argin	The string to send to the controller
 *	@return	The response from the controller
 *	@exception DevFailed
 */
    Tango::DevVarCharArray	*send(const Tango::DevVarCharArray *);

/**
 *	Read the device properties from database
 */
     void get_device_property();
//@}

    //	Here is the end of the automatic code generation part
    //-------------------------------------------------------------	



protected :	
    //	Add your own data members here
    //-----------------------------------------
};

}	// namespace_ns

#endif	// _CONTROLLER_H