--TEST--
Check for Yal\Acl\Acl::addResource(Resource\ResourceInterface|string $resource, Resource\ResourceInterface|string $parent)
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;

$acl = new Acl();
$resourceArea = new Resource\GenericResource('area');
$acl->addResource($resourceArea);
var_dump($acl);
?>
--EXPECTF--
object(Yal\Acl\Acl)#1 (6) {
  ["roleRegister":protected]=>
  NULL
  ["resources":protected]=>
  array(1) {
    ["area"]=>
    array(3) {
      ["instance"]=>
      object(Yal\Acl\Resource\GenericResource)#2 (1) {
        ["resourceId":protected]=>
        string(4) "area"
      }
      ["parent"]=>
      NULL
      ["children"]=>
      array(0) {
      }
    }
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
    array(1) {
      ["area"]=>
      array(3) {
        ["instance"]=>
        object(Yal\Acl\Resource\GenericResource)#2 (1) {
          ["resourceId":protected]=>
          string(4) "area"
        }
        ["parent"]=>
        NULL
        ["children"]=>
        array(0) {
        }
      }
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
        array(1) {
          ["area"]=>
          array(3) {
            ["instance"]=>
            object(Yal\Acl\Resource\GenericResource)#2 (1) {
              ["resourceId":protected]=>
              string(4) "area"
            }
            ["parent"]=>
            NULL
            ["children"]=>
            array(0) {
            }
          }
        }
      }
      ["byRoleId"]=>
      array(1) {
        ["area"]=>
        array(3) {
          ["instance"]=>
          object(Yal\Acl\Resource\GenericResource)#2 (1) {
            ["resourceId":protected]=>
            string(4) "area"
          }
          ["parent"]=>
          NULL
          ["children"]=>
          array(0) {
          }
        }
      }
    }
  }
}