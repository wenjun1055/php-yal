/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/
  
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_yal.h"

#include "acl/yal_acl_acl.h"
#include "acl/yal_acl_role_role_interface.h"
#include "acl/yal_acl_acl_interface.h"
#include "acl/yal_acl_role_generic_role.h"
#include "acl/yal_acl_role_registery.h"
#include "acl/yal_acl_resource_resource_interface.h"
#include "acl/yal_acl_resource_generic_resource.h"

/* {{{ ZEND_MINIT_FUNCTION
 */
ZEND_MINIT_FUNCTION(yal_acl)
{
    ZEND_MODULE_STARTUP_N(yal_acl_acl)(INIT_FUNC_ARGS_PASSTHRU);
    ZEND_MODULE_STARTUP_N(yal_acl_acl_interface)(INIT_FUNC_ARGS_PASSTHRU);
    ZEND_MODULE_STARTUP_N(yal_acl_role_role_interface)(INIT_FUNC_ARGS_PASSTHRU);
    ZEND_MODULE_STARTUP_N(yal_acl_role_generic_role)(INIT_FUNC_ARGS_PASSTHRU);
    ZEND_MODULE_STARTUP_N(yal_acl_role_registery)(INIT_FUNC_ARGS_PASSTHRU);
    ZEND_MODULE_STARTUP_N(yal_acl_resource_resource_interface)(INIT_FUNC_ARGS_PASSTHRU);
    ZEND_MODULE_STARTUP_N(yal_acl_resource_generic_resource)(INIT_FUNC_ARGS_PASSTHRU);
}
/* }}} */