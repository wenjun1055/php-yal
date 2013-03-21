--TEST--
Check for Yal\Acl\Acl::removeRoleAll()
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;

$acl = new Acl();
$roleGuest = new Role\GenericRole('guest');

$acl->addRole($roleGuest)
    ->removeRoleAll();
        
var_dump($acl->hasRole($roleGuest));    //bool(false)
?>
--EXPECTF--
bool(false)