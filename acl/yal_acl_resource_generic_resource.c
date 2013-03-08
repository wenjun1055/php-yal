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
#include "yal_acl_resource_generic_resource.h"
#include "yal_acl_resource_resource_interface.h"
  
zend_class_entry *yal_acl_resource_generic_resource_ce;

/** {{{ ARG_INFO
*/
ZEND_BEGIN_ARG_INFO_EX(yal_acl_resource_generic_resource_construct_arg, 0, 0, 1)
    ZEND_ARG_INFO(0, resourceId)
ZEND_END_ARG_INFO()
/* }}} */

/** {{{ proto public Yal\Acl\Resource\GenericResource::__construct($roleId)
 */
PHP_METHOD(yal_acl_resource_generic_resource, __construct) 
{
    char *resource_id;
    uint resource_id_len;
    zval *resource;
    
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &resource_id, &resource_id_len) == FAILURE) {
      RETURN_NULL();
    }
    
    MAKE_STD_ZVAL(resource);
    ZVAL_STRING(resource, resource_id, 1);
    zend_update_property(yal_acl_resource_generic_resource_ce, getThis(), ZEND_STRL(YAL_ACL_RESOURCE_GENERIC_RESOURCE_PROPERTY_NAME_RESOURCE_ID), resource TSRMLS_CC);
    zval_ptr_dtor(&resource);
}
/* }}} */

/** {{{ proto public Yal\Acl\Resource\GenericResource::getResourceId(void)
 */
PHP_METHOD(yal_acl_resource_generic_resource, getResourceId) 
{
    zval *resource;
    char *resource_id;
    resource = zend_read_property(yal_acl_resource_generic_resource_ce, getThis(), ZEND_STRL(YAL_ACL_RESOURCE_GENERIC_RESOURCE_PROPERTY_NAME_RESOURCE_ID), 1 TSRMLS_CC);
    convert_to_string_ex(&resource);
    RETURN_STRING(Z_STRVAL_P(resource), 1);
}
/* }}} */

/** {{{ proto public Yal\Acl\Resource\GenericResource::__toString(void)
 */
PHP_METHOD(yal_acl_resource_generic_resource, __toString) 
{
    zval *resource;
    char *resource_id;
    resource = zend_read_property(yal_acl_resource_generic_resource_ce, getThis(), ZEND_STRL(YAL_ACL_RESOURCE_GENERIC_RESOURCE_PROPERTY_NAME_RESOURCE_ID), 1 TSRMLS_CC);
    convert_to_string_ex(&resource);
    RETURN_STRING(Z_STRVAL_P(resource), 1);
}
/* }}} */

/** {{{ yal_acl_resource_generic_resource_methods
 */
zend_function_entry yal_acl_resource_generic_resource_methods[] = {
    PHP_ME(yal_acl_resource_generic_resource, __construct,     yal_acl_resource_generic_resource_construct_arg, ZEND_ACC_CTOR|ZEND_ACC_PUBLIC)
    PHP_ME(yal_acl_resource_generic_resource, getResourceId,   NULL,                                            ZEND_ACC_PUBLIC)
    PHP_ME(yal_acl_resource_generic_resource, __toString,      NULL,                                            ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};
/* }}} */

/** {{{ ZEND_MINIT_FUNCTION
 */
ZEND_MINIT_FUNCTION(yal_acl_resource_generic_resource)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Yal\\Acl\\Resource\\GenericResource", yal_acl_resource_generic_resource_methods);
    yal_acl_resource_generic_resource_ce = zend_register_internal_class_ex(&ce, NULL, NULL TSRMLS_CC);
    zend_class_implements(yal_acl_resource_generic_resource_ce TSRMLS_CC, 1, yal_acl_resource_resource_interface_ce);
    yal_acl_resource_generic_resource_ce->ce_flags |= ZEND_ACC_FINAL_CLASS;
    
    zend_declare_property_null(yal_acl_resource_generic_resource_ce, ZEND_STRL(YAL_ACL_RESOURCE_GENERIC_RESOURCE_PROPERTY_NAME_RESOURCE_ID), ZEND_ACC_PROTECTED TSRMLS_CC);
    
    return SUCCESS;
}
/* }}} */