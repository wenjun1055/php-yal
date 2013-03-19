--TEST--
Check for Yal\Acl\Acl::hasRole(Role\RoleInterface|string $role)
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;
$acl       = new Acl();
$roleGuest = new Role\GenericRole('guest');

$role = $acl->addRole($roleGuest)
            ->hasRole($roleGuest->getRoleId());
var_dump($role);

$role = $acl->hasRole($roleGuest);
var_dump($role);

$acl       = new Acl();
$role = $acl->addRole('area')
            ->hasRole('area');
var_dump($role);
?>
--EXPECTF--
bool(true)
bool(true)
bool(true)