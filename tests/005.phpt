--TEST--
Check for Yal\Acl\Role\Registery
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
$role = new Yal\Acl\Role\GenericRole('id_6');
var_dump($role->getRoleId());
$genericRole = new Yal\Acl\Role\Registery();
var_dump($genericRole->roles);
var_dump($genericRole->add($role, 'id_6'));
var_dump($genericRole->has('id_6'));
var_dump($genericRole->roles);
var_dump($genericRole->get('id_6'));
?>
--EXPECTF--
array(0) {
}
bool(false)