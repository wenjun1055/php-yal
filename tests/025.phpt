--TEST--
Check for Yal\Acl\Acl::addResource(Resource\ResourceInterface|string $resource, Resource\ResourceInterface|string $parent)
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;

$acl = new Acl();
$acl->addResource('12');

// $roleGuest = new Role\GenericRole('guest');

// $acl->addRole($roleGuest)
//     ->removeRoleAll();
        
// var_dump($acl->hasRole($roleGuest));    //bool(false)
?>
--EXPECTF--