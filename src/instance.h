#ifndef __INSTANCE_H__
#define __INSTANCE_H__

/*!
 \file    instance.h
 \author   Trevor Williams  (trevorw@charter.net)
 \date     3/11/2002
 \brief    Contains functions for handling module instances.
*/

#include "defines.h"
#include "module.h"


//! Finds specified scope in module instance tree.
mod_inst* instance_find_scope( mod_inst* root, char* scope );

//! Adds new instance to specified instance tree during parse.
void instance_parse_add( mod_inst** root, module* parent, module* child, char* inst_name );

//! Adds new instance to specified instance tree during CDD read.
void instance_read_add( mod_inst** root, char* parent, module* child, char* inst_name );

//! Displays contents of module instance tree to specified file.
void instance_db_write( mod_inst* root, FILE* file, char* scope );

//! Removes specified instance from tree.
void instance_dealloc( mod_inst* root, char* scope );

/* $Log$
/* Revision 1.3  2002/07/18 02:33:24  phase1geo
/* Fixed instantiation addition.  Multiple hierarchy instantiation trees should
/* now work.
/* */

#endif

