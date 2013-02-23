/*
  +----------------------------------------------------------------------+
  | Yet Another Framework                                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Jun Wen  <wenjun1055@gmail.com>                              |
  +----------------------------------------------------------------------+
*/
  
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_yal.h"
#include "yal_acl_role_role_interface.h"

zend_class_entry * yal_acl_role_role_interface_ce;

/** {{{ proto public Yal\\Acl\\Role\\RoleInterface::getRoleId()
 */
PHP_METHOD(yal_acl_role_role_interface, getRoleId)
{
}
/* }}} */

/** {{{ yal_acl_role_interface_methods
 */
static zend_function_entry yal_acl_role_role_interface_methods[] = {
    PHP_ME(yal_acl_role_role_interface, getRoleId, NULL, ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};
/* }}} */

/* {{{ ZEND_MINIT_FUNCTION
 */
ZEND_MINIT_FUNCTION(yal_acl_role_role_interface)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Yal\\Acl\\Role\\RoleInterface", yal_acl_role_role_interface_methods);
    yal_acl_role_role_interface_ce = zend_register_internal_class_ex(&ce, NULL, NULL TSRMLS_CC);
    yal_acl_role_role_interface_ce->ce_flags |= ZEND_ACC_INTERFACE;

    return SUCCESS;
}
/* }}} */
