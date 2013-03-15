--TEST--
Check for Yal\Acl\Role\Registery::add()
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;
$roleRegistery = new Role\Registery();
$roleGuest     = new Role\GenericRole('guest');
$roleMember    = new Role\GenericRole('member');
$roleAdmin     = new Role\GenericRole('admin');

$roleRegistery->add($roleGuest);
$roleRegistery->add($roleMember);
$roleRegistery->add($roleAdmin);
$parents = array('guest', 'member', 'admin');
$roleRegistery->add(new Role\GenericRole('someUser'), $parents);

var_dump($roleRegistery->inherits(new Role\GenericRole('someUser'), $roleGuest));
var_dump($roleRegistery->inherits(new Role\GenericRole('someUser'), $roleMember));
var_dump($roleRegistery->inherits(new Role\GenericRole('someUser'), $roleAdmin));
echo "\r\n";
var_dump($roleRegistery->inherits('someUser', $roleGuest));
var_dump($roleRegistery->inherits('someUser', $roleMember));
var_dump($roleRegistery->inherits('someUser', $roleAdmin));
echo "\r\n";
var_dump($roleRegistery->inherits(new Role\GenericRole('someUser'), 'guest'));
var_dump($roleRegistery->inherits(new Role\GenericRole('someUser'), 'member'));
var_dump($roleRegistery->inherits(new Role\GenericRole('someUser'), 'admin'));
echo "\r\n";
var_dump($roleRegistery->inherits('someUser', 'guest'));
var_dump($roleRegistery->inherits('someUser', 'member'));
var_dump($roleRegistery->inherits('someUser', 'admin'));
echo "\r\n";
var_dump($roleRegistery->inherits($roleAdmin, $roleAdmin));
var_dump($roleRegistery->inherits($roleGuest, $roleAdmin));
echo "\r\n";
var_dump($roleRegistery->inherits('admin', 'someUser'));
var_dump($roleRegistery->inherits('admin', 'member'));
?>
--EXPECTF--
