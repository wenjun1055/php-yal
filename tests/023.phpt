--TEST--
Check for Yal\Acl\Acl::removeRole(Role\RoleInterface|string $role)
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;
$acl = new Acl();

$acl->removeRole('nonexistent');

$roleGuest = new Role\GenericRole('guest');
$acl->addRole($roleGuest);
var_dump($acl->hasRole($roleGuest));
$acl->removeRole($roleGuest);
var_dump($acl->hasRole($roleGuest));
?>
--EXPECTF--
Warning: Yal\Acl\Role\Registery::get(): Role 'nonexistent' not found in /home/vagrant/php-5.3.10/ext/yal/tests/023.php on line 5
bool(true)
bool(false)