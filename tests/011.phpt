--TEST--
Check for Yal\Acl\Acl
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
$acl = new Yal\Acl\Acl();
var_dump($acl);
?>
--EXPECTF--
object(Yal\Acl\Acl)#1 (6) {
  ["roleRegister":protected]=>
  NULL
  ["resources":protected]=>
  array(0) {
  }
  ["isAllowedRole":protected]=>
  NULL
  ["isAllowedResource":protected]=>
  NULL
  ["isAllowedPrivilege":protected]=>
  NULL
  ["rules":protected]=>
  array(2) {
    ["byResourceId"]=>
    array(0) {
    }
    ["allResources"]=>
    array(2) {
      ["allRoles"]=>
      array(2) {
        ["allPrivileges"]=>
        array(2) {
          ["type"]=>
          string(9) "TYPE_DENY"
          ["assert"]=>
          NULL
        }
        ["byPrivilegeId"]=>
        array(0) {
        }
      }
      ["byRoleId"]=>
      array(0) {
      }
    }
  }
}