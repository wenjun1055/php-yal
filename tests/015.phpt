--TEST--
Check for Yal\Acl\Role\Registery::has()
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;
$roleRegistery = new Role\Registery();
$roleGuest     = new Role\GenericRole('area');
$roleRegistery->add($roleGuest);
var_dump($roleRegistery->has('area'));
var_dump($roleRegistery->has($roleGuest));
?>
--EXPECTF--
bool(true)
bool(true)