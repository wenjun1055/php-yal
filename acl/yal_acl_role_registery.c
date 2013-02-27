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
#include "yal_acl_role_registery.h"
#include "yal_acl_role_generic_role.h"
#include "yal_acl_role_role_interface.h"
  
#include "Zend/zend_interfaces.h" /* for zend_call_method_with_* */
  
zend_class_entry *yal_acl_role_registery_ce;

/** {{{ ARG_INFO
*/
ZEND_BEGIN_ARG_INFO_EX(yal_acl_role_registery_void_arg, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yal_acl_role_registery_add_arg, 0, 0, 1)
    ZEND_ARG_OBJ_INFO(0, role, Yal\\Acl\\Role\\GenericRole, 0)
    ZEND_ARG_INFO(0, parents)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yal_acl_role_registery_get_arg, 0, 0, 1)
    ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yal_acl_role_registery_has_arg, 0, 0, 1)
    ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yal_acl_role_registery_getParents_arg, 0, 0, 1)
    ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yal_acl_role_registery_remove_arg, 0, 0, 1)
    ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yal_acl_role_registery_inherits_arg, 0, 0, 2)
    ZEND_ARG_INFO(0, role)
    ZEND_ARG_INFO(0, inherit)
    ZEND_ARG_INFO(0, onlyParents)
ZEND_END_ARG_INFO()
/* }}} */

/** {{{ proto public Yal\Acl\Role\Registery::__construct(void)
 */
PHP_METHOD(yal_acl_role_registery, __construct) 
{
    zval *roles;
    MAKE_STD_ZVAL(roles);
    array_init(roles);
    add_assoc_long(roles, "id_5", 10);
    zend_update_property(yal_acl_role_registery_ce, getThis(), ZEND_STRL(YAL_ACL_ROLE_REGISTERY_PROPERTY_ROLES), roles TSRMLS_CC);
    zval_ptr_dtor(&roles);
}
/* }}} */

/** {{{ proto public Yal\Acl\Role\Registery::getRoles(RoleInterface $role, $parents = null)
 */
PHP_METHOD(yal_acl_role_registery, add) 
{
    zval *role_interface, *return_value_bool, *ret, *role_parents;
    zval *parents, *role_array, *temp_array_1, *temp_array_2, *parents_array; 
    zval **data, *role_parent_id, *role_parent;;
    HashTable *parents_hash;
    HashPosition pointer;
    
    MAKE_STD_ZVAL(parents);
    ZVAL_NULL(parents);
    
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O|z", &role_interface, yal_acl_role_role_interface_ce, &parents) == FAILURE) {
        RETURN_NULL();
    }
    
    if (IS_OBJECT != Z_TYPE_P(role_interface) ||
        !instanceof_function(Z_OBJCE_P(role_interface), yal_acl_role_role_interface_ce TSRMLS_CC)) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Expects a %s instance", yal_acl_role_role_interface_ce->name);
        RETURN_FALSE;
    }
    //printf("%s\n", Z_OBJCE_P(role_interface)->name);
    zend_call_method_with_0_params(&role_interface, Z_OBJCE_P(role_interface), NULL, "getroleid", &ret);
    convert_to_string_ex(&ret);
    //printf("%s\n", Z_STRVAL_P(ret));
    zend_call_method_with_1_params(&getThis(), Z_OBJCE_P(getThis()), NULL, "has", &return_value_bool, ret);
    convert_to_boolean_ex(&return_value_bool);
    //printf("%d\n", Z_BVAL_P(return_value_bool));
    if (Z_BVAL_P(return_value_bool)) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Role id '%s' already exists in the registry", Z_STRVAL_P(ret));
        RETURN_FALSE;
    }
    
    MAKE_STD_ZVAL(role_parents);
    array_init(role_parents);
    if (Z_TYPE_P(parents) != IS_NULL) {
        zval_add_ref(&parents);
        if (IS_ARRAY != Z_TYPE_P(parents)) {
            MAKE_STD_ZVAL(parents_array);
            array_init(parents_array);
            add_next_index_zval(parents_array, parents);
        }
        
        parents_hash = Z_ARRVAL_P(parents_array);
        zend_hash_internal_pointer_reset_ex(parents_hash, &pointer);
        while (zend_hash_get_current_data_ex(parents_hash, (void **)&data, &pointer) == SUCCESS) {
            zval_add_ref(data);
            printf("%d\n", Z_TYPE_PP(data));
            if (IS_OBJECT == Z_TYPE_PP(data) &&
                    instanceof_function(Z_OBJCE_PP(data), yal_acl_role_role_interface_ce TSRMLS_CC)) {
                zend_call_method_with_0_params(data, Z_OBJCE_PP(data), NULL, "getroleid", &role_parent_id);
            } else {
                *role_parent_id = **data;
            }
            zend_call_method_with_1_params(&getThis(), Z_OBJCE_P(getThis()), NULL, "get", &role_parent, role_parent_id);
            
            add_assoc_zval(role_parents, Z_STRVAL_P(role_parent_id), role_parent);
            zval *temp, *temp_1;
            MAKE_STD_ZVAL(temp);
            MAKE_STD_ZVAL(temp_1);
            array_init(temp);
            array_init(temp_1);
            add_assoc_zval(temp, Z_STRVAL_P(ret), role_interface);
            add_assoc_zval(temp_1, "children", temp);

            role_array = zend_read_property(yal_acl_role_registery_ce, getThis(), ZEND_STRL(YAL_ACL_ROLE_REGISTERY_PROPERTY_ROLES), 0 TSRMLS_CC);
            zval_add_ref(&role_array);
            convert_to_array_ex(&role_array);
            add_assoc_zval(role_array, Z_STRVAL_P(role_parent_id), temp_1);
            
            zend_update_property(yal_acl_role_registery_ce, getThis(), ZEND_STRL(YAL_ACL_ROLE_REGISTERY_PROPERTY_ROLES), role_array TSRMLS_CC);
            
            zval_dtor(temp);
            zval_dtor(temp_1);
            zend_hash_move_forward_ex(parents_hash, &pointer);
        }
    }
     
    role_array = zend_read_property(yal_acl_role_registery_ce, getThis(), ZEND_STRL(YAL_ACL_ROLE_REGISTERY_PROPERTY_ROLES), 0 TSRMLS_CC);
    zval_add_ref(&role_array);
    convert_to_array_ex(&role_array);
     
    MAKE_STD_ZVAL(temp_array_1);
    MAKE_STD_ZVAL(temp_array_2);
    array_init(temp_array_1);
    array_init(temp_array_2);
     
    add_assoc_zval(temp_array_1, "instance", role_interface);
    add_assoc_zval(temp_array_1, "parents", role_parents);
    add_assoc_zval(temp_array_1, "children", temp_array_2);
    add_assoc_zval(role_array,   Z_STRVAL_P(ret), temp_array_1);
     
    zend_update_property(yal_acl_role_registery_ce, getThis(), ZEND_STRL(YAL_ACL_ROLE_REGISTERY_PROPERTY_ROLES), role_array TSRMLS_CC);
    RETURN_ZVAL(getThis(), 1, 0);
}
/* }}} */

/** {{{ proto public Yal\Acl\Role\Registery::getRoles(void)
 */
// PHP_METHOD(yal_acl_role_registery, getRoles) 
// {
//     array_init(return_value);
//     return_value = zend_read_property(yal_acl_role_registery_ce, getThis(), ZEND_STRL(YAL_ACL_ROLE_REGISTERY_PROPERTY_ROLES), 1 TSRMLS_CC);
// }
/* }}} */

/** {{{ proto public Yal\Acl\Role\Registery::removeAll(void)
 */
// PHP_METHOD(yal_acl_role_registery, removeAll) 
// {
//     zval *array;
//     MAKE_STD_ZVAL(array);
//     array_init(array);
//     zend_update_property(yal_acl_role_registery_ce, getThis(), ZEND_STRL(YAL_ACL_ROLE_REGISTERY_PROPERTY_ROLES), array TSRMLS_CC);
//     RETURN_ZVAL(getThis(), 1, 0);
// }
/* }}} */

/** {{{ proto public Yal\Acl\Role\Registery::has(string $role)
 */
PHP_METHOD(yal_acl_role_registery, has) 
{
    zval *temp_role;
    char *role;
    uint role_len;
    int flag;
    HashTable *role_hash;
    
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &role, &role_len) == FAILURE) {
        RETURN_NULL();
    }

    temp_role = zend_read_property(yal_acl_role_registery_ce, getThis(), ZEND_STRL(YAL_ACL_ROLE_REGISTERY_PROPERTY_ROLES), 1 TSRMLS_CC);
    convert_to_array_ex(&temp_role);
    if (zend_hash_exists(Z_ARRVAL_P(temp_role), role, role_len+1)) {
        RETURN_BOOL(1);
    } else {
        RETURN_BOOL(0);
    }
}
/* }}} */

/** {{{ proto public Yal\Acl\Role\Registery::get(RoleInterface|string $role)
 */
PHP_METHOD(yal_acl_role_registery, get) 
{
    zval *role, *role_id, *role_boolean, *roles, **instance, **return_role_id;
    
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &role) == FAILURE) {
        RETURN_NULL();
    }
    
    if (IS_OBJECT == Z_TYPE_P(role) &&
        instanceof_function(Z_OBJCE_P(role), yal_acl_role_role_interface_ce TSRMLS_CC)) {
        zend_call_method_with_0_params(role, Z_OBJCE_P(role), NULL, "getroleid", &role_id);
    } else {
        *role_id = *role;
    }
    convert_to_string_ex(&role_id);
    //zval_add_ref(role_id);
    
    zend_call_method_with_1_params(&getThis(), Z_OBJCE_P(getThis()), NULL, "has", &role_boolean, role);
    convert_to_boolean_ex(&role_boolean);
    // printf("%d\n", Z_BVAL_P(role_boolean));
    if (! Z_BVAL_P(role_boolean)) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Role '%s' not found", Z_STRVAL_P(role_id));
        RETURN_FALSE;
    }
    
    roles = zend_read_property(yal_acl_role_registery_ce, getThis(), ZEND_STRL(YAL_ACL_ROLE_REGISTERY_PROPERTY_ROLES), 1 TSRMLS_CC);
    
    // //convert_to_array_ex(&roles);
    // //RETURN_ZVAL(roles, 1, 0);
    // printf("%d\n", Z_TYPE_P(roles));
    if (zend_hash_find(Z_ARRVAL_P(roles), Z_STRVAL_P(role_id), Z_STRLEN_P(role_id)+1, (void **)&instance) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Roles '%s' not found", Z_STRVAL_P(role_id));
    }
    // printf("%d\n", Z_TYPE_PP(instance));
    // *return_value = **instance;
    // convert_to_array_ex(return_value);
    // if (zend_hash_find(Z_ARRVAL_PP(instance), ZEND_STRS("instance"), (void **)&return_role_id) == SUCCESS) {
    //     printf("%d\n", Z_TYPE_PP(return_role_id));
    // }
    // //RETURN_ZVAL(return_value, 1, 0);
    // RETURN_FALSE;
}
/* }}} */






/** {{{ yal_acl_role_interface_methods
 */
zend_function_entry yal_acl_role_registery_methods[] = {
    PHP_ME(yal_acl_role_registery, __construct,        yal_acl_role_registery_void_arg,    ZEND_ACC_CTOR|ZEND_ACC_PUBLIC)
    PHP_ME(yal_acl_role_registery, add,        yal_acl_role_registery_add_arg,                    ZEND_ACC_PUBLIC)
    PHP_ME(yal_acl_role_registery, get,        yal_acl_role_registery_get_arg,                    ZEND_ACC_PUBLIC)
    PHP_ME(yal_acl_role_registery, has,        yal_acl_role_registery_has_arg,                    ZEND_ACC_PUBLIC)
    //PHP_ME(yal_acl_role_registery, getParents, yal_acl_role_registery_getParents_arg,             ZEND_ACC_PUBLIC)
    //PHP_ME(yal_acl_role_registery, inherits,   yal_acl_role_registery_inherits_arg,               ZEND_ACC_PUBLIC)
    //PHP_ME(yal_acl_role_registery, remove,     yal_acl_role_registery_remove_arg,                 ZEND_ACC_PUBLIC)
    //PHP_ME(yal_acl_role_registery, removeAll,  yal_acl_role_registery_void_arg,                   ZEND_ACC_PUBLIC)
    //PHP_ME(yal_acl_role_registery, getRoles,   yal_acl_role_registery_void_arg,                   ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};

/* }}} */

/** {{{ ZEND_MINIT_FUNCTION
 */
ZEND_MINIT_FUNCTION(yal_acl_role_registery)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Yal\\Acl\\Role\\Registery", yal_acl_role_registery_methods);
    yal_acl_role_registery_ce = zend_register_internal_class_ex(&ce, NULL, NULL TSRMLS_CC);
    yal_acl_role_registery_ce->ce_flags |= ZEND_ACC_FINAL_CLASS;
    
    zend_declare_property_null(yal_acl_role_registery_ce, ZEND_STRL(YAL_ACL_ROLE_REGISTERY_PROPERTY_ROLES), ZEND_ACC_PUBLIC TSRMLS_CC);
    
    return SUCCESS;
}
/* }}} */