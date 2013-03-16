--TEST--
Check for Yal\Acl\Acl::addRole($role, $parents = null)
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
$roleGuest = new Yal\Acl\Role\GenericRole('guest');
$acl = new Yal\Acl\Acl();
$acl->addRole($roleGuest);
var_dump($acl);
?>
--EXPECTF--
object(Yal\Acl\Acl)#2 (6) {
  ["roleRegister":protected]=>
  object(Yal\Acl\Role\Registery)#3 (1) {
    ["roles"]=>
    array(1) {
      ["guest"]=>
      array(3) {
        ["instance"]=>
        object(Yal\Acl\Role\GenericRole)#1 (1) {
          ["roleId":protected]=>
          string(5) "guest"
        }
        ["parents"]=>
        array(0) {
        }
        ["children"]=>
        array(0) {
        }
      }
    }
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