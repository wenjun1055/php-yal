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
  
#ifndef YAL_ACL_ACL_INTERFACE_H
#define YAL_ACL_ACL_INTERFACE_H

extern zend_class_entry *yal_acl_acl_interface_ce;

PHP_METHOD(yal_acl_acl_interface, hasResource);
PHP_METHOD(yal_acl_acl_interface, isAllowed);

ZEND_MINIT_FUNCTION(yal_acl_acl_interface);
#endif
/*
 *Local variables:
 *tab-width: 4
 *c-basic-offset: 4
 *End:
 *vim600: noet sw=4 ts=4 fdm=marker
 *vim<600: noet sw=4 ts=4
 */
