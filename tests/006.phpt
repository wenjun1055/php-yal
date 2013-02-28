--TEST--
Check for Yal\Acl\Role\Registery::add()
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;
$roleRegistery = new Role\Registery();
$roleAdmin     = new Role\GenericRole('admin');
$roleRegistery->add($roleAdmin);
$roleRegistery->add($roleAdmin);
?>
--EXPECTF--
Warning: Yal\Acl\Role\Registery::add(): Role id 'admin' already exists in the registry in /home/vagrant/php-5.3.10/ext/yal/tests/006.php on line 6