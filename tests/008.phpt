--TEST--
Check for Yal\Acl\Role\Registery::add()
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;
$roleRegistery = new Role\Registery();
$roleGuest     = new Role\GenericRole('guest');
$roleMember    = new Role\GenericRole('member');
$roleAdmin     = new Role\GenericRole('admin');

$roleRegistery->add($roleGuest);
$roleRegistery->add($roleMember);
$roleRegistery->add($roleAdmin);
$parents = array('guest', 'member', 'admin');
$roleRegistery->add(new Role\GenericRole('someUser'), 'member');
var_dump($roleRegistery);
?>
--EXPECTF--
object(Yal\Acl\Role\Registery)#1 (1) {
  ["roles"]=>
  array(4) {
    ["guest"]=>
    array(3) {
      ["instance"]=>
      object(Yal\Acl\Role\GenericRole)#2 (1) {
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
    ["member"]=>
    array(3) {
      ["instance"]=>
      object(Yal\Acl\Role\GenericRole)#3 (1) {
        ["roleId":protected]=>
        string(6) "member"
      }
      ["parents"]=>
      array(0) {
      }
      ["children"]=>
      array(1) {
        ["someUser"]=>
        object(Yal\Acl\Role\GenericRole)#5 (1) {
          ["roleId":protected]=>
          string(8) "someUser"
        }
      }
    }
    ["admin"]=>
    array(3) {
      ["instance"]=>
      object(Yal\Acl\Role\GenericRole)#4 (1) {
        ["roleId":protected]=>
        string(5) "admin"
      }
      ["parents"]=>
      array(0) {
      }
      ["children"]=>
      array(0) {
      }
    }
    ["someUser"]=>
    array(3) {
      ["instance"]=>
      object(Yal\Acl\Role\GenericRole)#5 (1) {
        ["roleId":protected]=>
        string(8) "someUser"
      }
      ["parents"]=>
      array(1) {
        ["member"]=>
        object(Yal\Acl\Role\GenericRole)#3 (1) {
          ["roleId":protected]=>
          string(6) "member"
        }
      }
      ["children"]=>
      array(0) {
      }
    }
  }
}