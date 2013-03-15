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