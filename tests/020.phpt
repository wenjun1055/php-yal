--TEST--
Check for Yal\Acl\Acl::getRole(Role\RoleInterface|string $role)
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;
$acl       = new Acl();
$roleGuest = new Role\GenericRole('guest');

$role = $acl->addRole($roleGuest)
            ->getRole($roleGuest->getRoleId());
if ($role === $roleGuest) {
    var_dump('yes');
} else {
    var_dump('no');
}

$role = $acl->getRole($roleGuest);
if ($role === $roleGuest) {
    var_dump('yes');
} else {
    var_dump('no');
}

$acl       = new Acl();
$role = $acl->addRole('area')
            ->getRole('area');
if ($role instanceof Role\RoleInterface) {
    var_dump('role is instance of Role\RoleInterface');
} else {
    var_dump('role is not instance of Role\RoleInterface');
}
if ('area' === $role->getRoleId()) {
    var_dump('yes');
} else {
    var_dump('no');
}
?>
--EXPECTF--
string(3) "yes"
string(3) "yes"
string(38) "role is instance of Role\RoleInterface"
string(3) "yes"
