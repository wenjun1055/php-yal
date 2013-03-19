--TEST--
Check for Yal\Acl\Acl::inheritsRole(Role\RoleInterface|string $role
                                    Role\RoleInterface|string $inherit
                                    bool $onlyParents)
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;
$acl = new Acl();

$role = $acl->addRole(new Role\GenericRole('grandparent'))
            ->addRole(new Role\GenericRole('parent'), 'grandparent')
            ->addRole(new Role\GenericRole('child'), 'parent');

var_dump($acl->inheritsRole('child', 'grandparent', true));
?>
--EXPECTF--
bool(false)