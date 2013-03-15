--TEST--
Check for Yal\Acl\Role\Registery::add()
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;
$roleRegistery = new Role\Registery();
$roleGuest     = new Role\GenericRole('area');
$roleRegistery->add($roleGuest);
var_dump($roleRegistery->get('area'));
var_dump($roleRegistery->get($roleGuest));
?>
--EXPECTF--
