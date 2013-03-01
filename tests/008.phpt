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