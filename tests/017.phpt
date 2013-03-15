--TEST--
Check for Yal\Acl\Role\Registery::removeAll()
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;
$roleRegistery = new Role\Registery();
$roleGuest     = new Role\GenericRole('guest');
$memberGuest   = new Role\GenericRole('member');
var_dump($roleRegistery);
$roleRegistery->add($roleGuest);
var_dump($roleRegistery);
$roleRegistery->add($memberGuest);
var_dump($roleRegistery);
var_dump($roleRegistery->removeAll());
?>
--EXPECTF--
object(Yal\Acl\Role\Registery)#1 (1) {
  ["roles"]=>
  array(0) {
  }
}
object(Yal\Acl\Role\Registery)#1 (1) {
  ["roles"]=>
  array(1) {
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
  }
}
object(Yal\Acl\Role\Registery)#1 (1) {
  ["roles"]=>
  array(2) {
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
      array(0) {
      }
    }
  }
}
object(Yal\Acl\Role\Registery)#1 (1) {
  ["roles"]=>
  array(0) {
  }
}