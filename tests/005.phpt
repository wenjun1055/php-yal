--TEST--
Check for Yal\Acl\Role\Registery::add()
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;
$roleRegistery = new Role\Registery();
$roleRegistery->add('sss');
?>
--EXPECTF--
Catchable fatal error: Argument 1 passed to Yal\Acl\Role\Registery::add() must be an instance of Yal\Acl\Role\GenericRole, string given in /home/vagrant/php-5.3.10/ext/yal/tests/005.php on line 4