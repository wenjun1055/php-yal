--TEST--
Check for yal Yal\Acl\Role\RoleInterface
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
class RoleInterfaceTest implements Yal\Acl\Role\RoleInterface
{
	public function getRoleId()
	{
		return 'getRoleId';
	}
}
$acl = new RoleInterfaceTest();
var_dump($acl->getRoleId());
?>
--EXPECTF--
string(9) "getRoleId"