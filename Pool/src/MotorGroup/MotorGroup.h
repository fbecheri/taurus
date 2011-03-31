//=============================================================================
//
// file :        MotorGroup.h
//
// description : Include for the MotorGroup class.
//
// project :	Manage a group of motors
//
// $Author$
//
// $Revision$
//
// $Log$
// Revision 1.29  2007/08/30 12:40:39  tcoutinho
// - changes to support Pseudo counters.
//
// Revision 1.28  2007/08/17 13:07:29  tcoutinho
// - pseudo motor restructure
// - pool base dev class restructure
// - initial commit for pseudo counters
//
// Revision 1.27  2007/07/26 10:25:15  tcoutinho
// - Fix bug 1 :  Automatic temporary MotorGroup/MeasurementGroup deletion
//
// Revision 1.26  2007/05/25 07:20:02  tcoutinho
// - fix internal event propagation to ghost motor group when client asks for state and the new calculated state is different from the one previously stored
//
// Revision 1.25  2007/05/16 16:26:22  tcoutinho
// - fix dead lock
//
// Revision 1.24  2007/04/30 14:51:20  tcoutinho
// - make possible to Add/Remove elements on motorgroup that are part of other motor group(s)
//
// Revision 1.23  2007/04/26 08:23:04  tcoutinho
// - implemented add/remove elements feature
//
// Revision 1.22  2007/04/23 15:18:59  tcoutinho
// - first changes according to Sardana metting 26-03-2007: identical motor groups can be created, Add/Remove element from a MG, etc
//
// Revision 1.21  2007/02/22 11:58:12  tcoutinho
// - pool_elem_changed now is available on the super class
//
// Revision 1.20  2007/02/16 10:03:17  tcoutinho
// - development checkin related with measurement group
//
// Revision 1.19  2007/02/13 14:39:42  tcoutinho
// - fix bug in motor group when a motor or controller are recreated due to an InitController command
//
// Revision 1.18  2007/02/08 08:54:24  etaurel
// - Many changes. I don't remember the list
//
// Revision 1.17  2007/02/07 16:53:05  tcoutinho
// safe guard commit
//
// Revision 1.16  2007/02/06 19:36:51  tcoutinho
// safe guard commit
//
// Revision 1.15  2007/02/06 09:37:45  tcoutinho
// - Motor Group now uses PoolGroupBaseDev
//
// Revision 1.14  2007/01/23 08:30:12  tcoutinho
// -fixed error when user does not specify the pseudo_motor_roles attribute (case of only one pseudo motor)
//
// Revision 1.13  2007/01/16 14:27:45  etaurel
// - Change some names in the Pool structures
//
// Revision 1.12  2007/01/05 13:03:56  tcoutinho
// -changes to internal event mechanism
// -support for gcc 4.1.1 compilation without errors
//
// Revision 1.11  2006/12/20 10:26:08  tcoutinho
// - changes to support internal event propagation
// - bug fix in motor groups containing other motor groups or pseudo motors
//
// Revision 1.10  2006/12/12 11:09:20  tcoutinho
// - support for pseudo motors and motor groups in a motor group
//
// Revision 1.9  2006/12/11 16:37:27  tcoutinho
// - safety commit (before supporting pseudo motors in motor groups)
//
// Revision 1.8  2006/12/05 10:13:46  etaurel
// - Add a check on ctrl validity in the always_executed_hook() and a dev_status() method
//
// Revision 1.7  2006/11/20 14:35:16  etaurel
// - Add ghost group and event on group position
//
// Revision 1.6  2006/11/03 15:48:28  etaurel
// - Miscellaneous changes that I don't remember
//
// Revision 1.5  2006/10/25 10:05:20  etaurel
// - Complete implementation of the ReloadControllerCode command
// - Handle end of movment when reading position in polling mode
//
// Revision 1.4  2006/10/20 15:42:38  etaurel
// - First release with GetControllerInfo command supported and with
// controller properties
//
// Revision 1.3  2006/08/08 12:16:55  etaurel
// - It now uses the multi-motor controller interface
//
// Revision 1.2  2006/07/07 12:40:18  etaurel
// - Commit after implementing the group multi motor read
//
// Revision 1.1  2006/03/29 07:09:59  etaurel
// - Added motor group features
//
// copyleft :     CELLS/ALBA
//				  Edifici Ciències Nord. Mòdul C-3 central.
//  			  Campus Universitari de Bellaterra. Universitat Autònoma de Barcelona
//  			  08193 Bellaterra, Barcelona
//  			  Spain
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================
#ifndef _MOTORGROUP_H
#define _MOTORGROUP_H

#include "PoolGroupBaseDev.h"
#include "CPoolDefs.h"

namespace Pool_ns
{
    class Pool;
    struct ControllerPool;
    struct MotorPool;
    struct MotorGroupPool;
    struct PseudoMotorPool;
}

namespace Motor_ns
{
    class Motor;
}

namespace PseudoMotor_ns
{
    class PseudoMotor;
}


//using namespace Tango;

/**
 * @author	$Author$
 * @version	$Revision$
 */

 //	Add your own constants definitions here.
 //-----------------------------------------------

class PseudoMotorController;

namespace MotorGroup_ns
{

/**
 * Class Description:
 * This class manages a motor group
 */

/*
 *	Device States Description:
 *  Tango::ON :      All motors are ON
 *  Tango::ALARM :   At least one motor in the group is in ALARM state
 *  Tango::MOVING :  At least one of the motor in the group is MOVING
 *  Tango::FAULT :   At least one motor in the group is in FAULT mode
 */

class MotorGroup: public Pool_ns::PoolGroupBaseDev
//class MotorGroup: public Tango::Device_4Impl
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
        Tango::DevDouble	*attr_Position_read;
        Tango::DevDouble	attr_Position_write;
        Tango::DevString	*attr_Elements_read;
        Tango::DevString	*attr_Motors_read;
        Tango::DevString	*attr_MotorGroups_read;
        Tango::DevString	*attr_PseudoMotors_read;
//@}

/**
 *	@name Device properties
 *	Device properties member data.
 */
//@{
/**
 *	The motor group pool device name
 */
    string	pool_device;
/**
 *	List of user motors 
 */
    vector<Tango::DevLong>	motor_list;
/**
 *	List of user motor groups
 */
    vector<Tango::DevLong>	motor_group_list;
/**
 *	List of user pseudo motors 
 */
    vector<Tango::DevLong>	pseudo_motor_list;
/**
 *	Number of mS to sleep before the last read during a motor movment
 */
    Tango::DevLong	sleep_bef_last_read;
/**
 *	List of group element for the user point of view
 */
    vector<Tango::DevLong>	user_group_elt;
/**
 *	List of group element for the physical point of view
 */
    vector<Tango::DevLong>	phys_group_elt;
/**
 *	Size of the spectrum which should be written when the group Position
 *	attribute is written
 */
    Tango::DevLong	pos_spectrum_dim_x;
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
    MotorGroup(Tango::DeviceClass *cl,string &s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
    MotorGroup(Tango::DeviceClass *cl,const char *s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device name
 *	@param d	Device description.
 */
    MotorGroup(Tango::DeviceClass *cl,const char *s,const char *d);
//@}

/**@name Destructor
 * Only one desctructor is defined for this class */
//@{
/**
 * The object desctructor.
 */	
    ~MotorGroup() {delete_device();};
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
 * @name MotorGroup methods prototypes
 */

//@{
/**
 *	Hardware acquisition for attributes.
 */
    virtual void read_attr_hardware(vector<long> &attr_list);
/**
 *	Extract real attribute values for Position acquisition result.
 */
    virtual void read_Position(Tango::Attribute &attr);
/**
 *	Write Position attribute values to hardware.
 */
    virtual void write_Position(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for Elements acquisition result.
 */
    virtual void read_Elements(Tango::Attribute &attr);	
/**
 *	Extract real attribute values for Motors acquisition result.
 */
    virtual void read_Motors(Tango::Attribute &attr);	
/**
 *	Extract real attribute values for MotorGroups acquisition result.
 */
    virtual void read_MotorGroups(Tango::Attribute &attr);	
/**
 *	Extract real attribute values for MotorGroups acquisition result.
 */
    virtual void read_PseudoMotors(Tango::Attribute &attr);	
/**
 *	Read/Write allowed for Position attribute.
 */
    virtual bool is_Position_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for Elements attribute.
 */
    virtual bool is_Elements_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for Motors attribute.
 */
    virtual bool is_Motors_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for MotorGroups attribute.
 */
    virtual bool is_MotorGroups_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for PseudoMotors attribute.
 */
    virtual bool is_PseudoMotors_allowed(Tango::AttReqType type);
/**
 *	Execution allowed for Abort command.
 */
    virtual bool is_Abort_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for AddElement command.
 */
    virtual bool is_AddElement_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for RemoveElement command.
 */
    virtual bool is_RemoveElement_allowed(const CORBA::Any &any);
    
/**
 * This command gets the device state (stored in its <i>device_state</i> data member) and returns it to the caller.
 *	@return	State Code
 *	@exception DevFailed
 */
    virtual Tango::DevState	dev_state();
/**
 * This command gets the device status (stored in its <i>device_status</i> data member) and returns it to the caller.
 *	@return	Status description
 *	@exception DevFailed
 */
    virtual Tango::ConstDevString	dev_status();
/**
 * Abort movement of all motors moving when the command is executed
 *	@exception DevFailed
 */
    void	abort();
/**
 * Append a new element (motor, pseudo motor or motor group) to the motor group.
 *	@param	argin	Element name
 *	@exception DevFailed
 */
    void	add_element(Tango::DevString);
/**
 * Removes the element (motor, pseudo motor or motor group) from the motor group.
 *	@param	argin	Element name
 *	@exception DevFailed
 */
    void	remove_element(Tango::DevString);	

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

    struct IndMov: public Pool_ns::IndEltGrp
    {
        int32_t					idx_in_grp;	///< physical motor list index
        int32_t					idx_in_usr;	///< user motor list index

        IndMov(Pool_ns::MotorPool &, Pool_ns::CtrlGrp *ctrl_ptr,
               Tango::Device_4Impl *device, Pool_ns::ElementId, 
               Tango::Device_4Impl *dev = NULL);
        
        virtual ~IndMov() {}
        
        virtual const char *get_family()	{ return "Motor"; }
        Pool_ns::MotorPool *get_motor();
        Motor_ns::Motor *get_motor_device();
    };
    
    struct GrpInGrp
    {
        Pool_ns::ElementId		grp_id;
        Pool_ns::MotorGroupPool	&pool_grp;
        MotorGroup              *dev;
        int32_t					mot_nb;
        int32_t					usr_elts_nb;
        int32_t					pos_len;
        int32_t					start_idx;
        int32_t					idx_in_usr;			///< user motor list index
        
        GrpInGrp(Pool_ns::MotorGroupPool &ref, MotorGroup *mg);
        
        GrpInGrp &operator=(const GrpInGrp &rhs);
    };

    struct PsmInGrp
    {
        PsmInGrp(Pool_ns::PseudoMotorPool &ref, 
                 PseudoMotor_ns::PseudoMotor *pm_dev);

        PsmInGrp &operator=(const PsmInGrp &rhs);
    
        int32_t						mot_nb;			///< number of physical motors
        int32_t						start_idx;		///< physical motor list start index
        int32_t						idx_in_usr;		///< user motor list index
        int32_t						psm_ctrl_idx;	///< index of the PsmCtrlInGrp
        Pool_ns::PseudoMotorPool 	&pool_psm;
        PseudoMotor_ns::PseudoMotor *dev;
        string						psm_alias;
    };
    
    struct PsmCtrlInGrp
    {
        PsmCtrlInGrp(PseudoMotorController *ref):
        first_usr_psm(NULL), pool_psm_ctrl(ref)	{ }
        
        PsmCtrlInGrp &operator=(const PsmCtrlInGrp &rhs)
        {
            mot_nb=rhs.mot_nb;start_idx=rhs.start_idx;
            psm_in_grp_idx=rhs.psm_in_grp_idx;pool_psm_ctrl=rhs.pool_psm_ctrl;
            is_complete = rhs.is_complete; mot_count = rhs.mot_count;
            pm_count = rhs.pm_count; first_usr_psm = rhs.first_usr_psm; 
            return *this;
        }
        
        int32_t					mot_nb;				///< number of physical motors
        int32_t					start_idx;			///< physical motor list start index
        vector<int32_t>			psm_in_grp_idx;		///< list of indexes in the user motor list for each pseudo motor. If the pseudo motor is not present the vector element will contain a value of -1.
        PsmInGrp				*first_usr_psm;     ///< first user pseudo motor
        PseudoMotorController	*pool_psm_ctrl;
        bool					is_complete;		///< true means all pseudo motors that belong to this controller are present in the motor group
        int32_t					mot_count;
        int32_t					pm_count;
    };
    
    vector<Pool_ns::GrpEltType>		user_group_elt_type;
    vector<GrpInGrp>				grp_in_grp;
    vector<PsmInGrp>				psm_in_grp;
    vector<PsmCtrlInGrp>			psm_ctrls_in_grp;		///< list of pseudo motor controllers implied in the group
    Tango::DevDouble				*phys_mot_pos;
    
    int32_t                     nb_psm_in_grp;
    int32_t                     nb_grp_in_grp;
    
    virtual void init_pool_element(Pool_ns::PoolElement *);
    
    virtual void State_all_ind(vector<Controller *> &);
    virtual void State_ctrl_ind(Pool_ns::CtrlGrp *ctrl_grp, vector<Controller *> &);
    
    virtual void handle_temporary_siblings();
    
    void from_phys_2_grp();
    void from_grp_2_phys(const Tango::DevDouble *);
    
    IndMov &get_ind_mov_from_id(Pool_ns::ElementId id);
    IndMov &get_ind_mov_from_name(string &);
    
    PsmInGrp &get_psm_from_name(string &);
    
    GrpInGrp &get_grp_from_id(Pool_ns::ElementId id);
    GrpInGrp &get_grp_from_name(string &);
    
    void update_elements();
    
    vector<string>::iterator find_in_user_group_lst(string &);
    vector<string>::iterator find_in_phys_group_lst(string &);
    vector<string>::iterator find_in_motor_lst(string &);
    vector<string>::iterator find_in_motor_group_lst(string &);
    vector<string>::iterator find_in_pseudo_motor_lst(string &);
    
    Pool_ns::CtrlGrp * build_mot_ctrl(Pool_ns::ControllerPool &);
    IndMov *build_motor(Pool_ns::MotorPool &);
    
public:
    time_t						sbr_sec;
    int32_t						sbr_nsec;
    
    void build_grp_struct();
    virtual void build_grp();
    
    virtual void base_abort(bool);
    
    void add_motor_to_ghost_group(Pool_ns::ElementId );
    void remove_motor_from_ghost_group(Pool_ns::ElementId);
    void update_motor_info(Pool_ns::ElementId );
    
    inline int32_t get_physical_index_in_group(Pool_ns::ElementId id)
    {
        return get_ind_mov_from_id(id).idx_in_grp;
    }
    
    inline double get_phys_motor_pos(int32_t phy_idx_in_grp) 
    { 
        return phys_mot_pos[phy_idx_in_grp]; 
    }
    
    void update_state_from_ctrls(int32_t idx = -1, Tango::DevState state = Tango::ON);
    
    virtual void pool_elem_changed(Pool_ns::PoolElemEventList &, Pool_ns::PoolElementEvent &);
    
    Pool_ns::MotorGroupPool &get_motor_group_obj();
};

class GhostMotorGroup : public MotorGroup
{
public:

    GhostMotorGroup(Tango::DeviceClass *cl,string &s)
    :MotorGroup(cl, s) {}

    GhostMotorGroup(Tango::DeviceClass *cl,const char *s)
    :MotorGroup(cl, s) {}

    GhostMotorGroup(Tango::DeviceClass *cl,const char *s,const char *d)
    :MotorGroup(cl, s, d) {}
    
protected:
    
//    virtual void read_state_from_ctrls() 
//    { read_state_from_ctrls_lockone(); }
};

}	// namespace_ns

#endif	// _MOTORGROUP_H