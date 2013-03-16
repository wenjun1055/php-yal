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

#ifdef HAVA_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "php_yal.h"
#include "yal_acl_role_generic_role.h"
#include "yal_acl_role_role_interface.h"
  
zend_class_entry *yal_acl_role_generic_role_ce;

/** {{{ ARG_INFO
*/
ZEND_BEGIN_ARG_INFO_EX(yal_acl_role_generic_role_construct_arg, 0, 0, 1)
    ZEND_ARG_INFO(0, roleId)
ZEND_END_ARG_INFO()
/* }}} */

/** {{{ proto public Yal\Acl\Role\GenericRole::__construct($roleId)
 */
PHP_METHOD(yal_acl_role_generic_role, __construct) 
{
    char *role_id;
    uint role_id_len;
    zval *role;
    
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &role_id, &role_id_len) == FAILURE) {
      RETURN_NULL();
    }
    
    MAKE_STD_ZVAL(role);
    ZVAL_STRING(role, role_id, 1);
    zend_update_property(yal_acl_role_generic_role_ce, getThis(), ZEND_STRL(YAL_ACL_ROLE_GENERIC_ROLE_PROPERTY_NAME_ROLE_ID), role TSRMLS_CC);
    zval_ptr_dtor(&role);
    RETURN_ZVAL(getThis(), 1, 0);
}
/* }}} */

/** {{{ proto public Yal\Acl\Role\GenericRole::getRoleId(void)
 */
PHP_METHOD(yal_acl_role_generic_role, getRoleId) 
{
    zval *role;
    char *role_id;
    role = zend_read_property(yal_acl_role_generic_role_ce, getThis(), ZEND_STRL(YAL_ACL_ROLE_GENERIC_ROLE_PROPERTY_NAME_ROLE_ID), 1 TSRMLS_CC);
    convert_to_string_ex(&role);
    RETURN_STRING(Z_STRVAL_P(role), 1);
}
/* }}} */

/** {{{ proto public Yal\Acl\Role\GenericRole::__toString(void)
 */
PHP_METHOD(yal_acl_role_generic_role, __toString) 
{
    zval *role;
    char *role_id;
    role = zend_read_property(yal_acl_role_generic_role_ce, getThis(), ZEND_STRL(YAL_ACL_ROLE_GENERIC_ROLE_PROPERTY_NAME_ROLE_ID), 1 TSRMLS_CC);
    convert_to_string_ex(&role);
    RETURN_STRING(Z_STRVAL_P(role), 1);
}
/* }}} */

/** {{{ yal_acl_role_generic_role_methods
 */
zend_function_entry yal_acl_role_generic_role_methods[] = {
    PHP_ME(yal_acl_role_generic_role, __construct, yal_acl_role_generic_role_construct_arg, ZEND_ACC_CTOR|ZEND_ACC_PUBLIC)
    PHP_ME(yal_acl_role_generic_role, getRoleId,   NULL,      ZEND_ACC_PUBLIC)
    PHP_ME(yal_acl_role_generic_role, __toString,  NULL,      ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};
/* }}} */

/** {{{ ZEND_MINIT_FUNCTION
 */
ZEND_MINIT_FUNCTION(yal_acl_role_generic_role)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Yal\\Acl\\Role\\GenericRole", yal_acl_role_generic_role_methods);
    yal_acl_role_generic_role_ce = zend_register_internal_class_ex(&ce, NULL, NULL TSRMLS_CC);
    zend_class_implements(yal_acl_role_generic_role_ce TSRMLS_CC, 1, yal_acl_role_role_interface_ce);
    yal_acl_role_generic_role_ce->ce_flags |= ZEND_ACC_FINAL_CLASS;
    
    zend_declare_property_null(yal_acl_role_generic_role_ce, ZEND_STRL(YAL_ACL_ROLE_GENERIC_ROLE_PROPERTY_NAME_ROLE_ID), ZEND_ACC_PROTECTED TSRMLS_CC);
    
    return SUCCESS;
}
/* }}} */