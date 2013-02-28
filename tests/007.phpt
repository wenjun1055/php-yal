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

if ($roleRegistery->add($roleAdmin) == $roleRegistery) {
	var_dump('yes');
} else {
	var_dump('no');
}
var_dump($roleRegistery);
?>
--EXPECTF--
string(3) "yes"
object(Yal\Acl\Role\Registery)#1 (1) {
  ["roles"]=>
  array(3) {
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
  }
}