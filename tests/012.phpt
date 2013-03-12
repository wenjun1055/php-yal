--TEST--
Check for Yal\Acl\Acl::getRoleRegistry(void)
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
$acl = new Yal\Acl\Acl();
var_dump($acl->getRoleRegistry());
echo "\r\n";
var_dump($acl->getRoleRegistry());
echo "\r\n";
var_dump($acl);
?>
--EXPECTF--
object(Yal\Acl\Role\Registery)#2 (1) {
  ["roles"]=>
  NULL
}

object(Yal\Acl\Role\Registery)#2 (1) {
  ["roles"]=>
  NULL
}

object(Yal\Acl\Acl)#1 (6) {
  ["roleRegister":protected]=>
  object(Yal\Acl\Role\Registery)#2 (1) {
    ["roles"]=>
    NULL
  }
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