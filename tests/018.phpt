--TEST--
Check for Yal\Acl\Role\Registery::remove()
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
$roleRegistery->add($memberGuest);

var_dump($roleRegistery);

$roleRegistery->remove($roleGuest);
var_dump($roleRegistery);

$roleRegistery->remove('member');
var_dump($roleRegistery);
?>
--EXPECTF--
