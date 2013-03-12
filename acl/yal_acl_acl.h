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
  
#ifndef YAL_ACL_ACL_H
#define YAL_ACL_ACL_H

#define YAL_ACL_ACL_PROPERTY_NAME_TYPE_ALLOW            "TYPE_ALLOW"
#define YAL_ACL_ACL_PROPERTY_NAME_TYPE_DENY             "TYPE_DENY"
#define YAL_ACL_ACL_PROPERTY_NAME_OP_ADD                "OP_ADD"
#define YAL_ACL_ACL_PROPERTY_NAME_OP_REMOVE             "OP_REMOVE"

#define YAL_ACL_ACL_PROPERTY_NAME_ROLE_REGISTER         "roleRegister"
#define YAL_ACL_ACL_PROPERTY_NAME_RESOURCES             "resources"
#define YAL_ACL_ACL_PROPERTY_NAME_IS_ALLOWED_ROLE       "isAllowedRole"
#define YAL_ACL_ACL_PROPERTY_NAME_IS_ALLOWED_RESOURCE   "isAllowedResource"
#define YAL_ACL_ACL_PROPERTY_NAME_IS_ALLOWED_PRIVILEGE  "isAllowedPrivilege"
#define YAL_ACL_ACL_PROPERTY_NAME_RELES                 "rules"

extern zend_class_entry *yal_acl_acl_ce;

ZEND_MINIT_FUNCTION(yal_acl_acl);
#endif
