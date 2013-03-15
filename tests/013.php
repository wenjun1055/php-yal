<?php
$roleGuest = new Yal\Acl\Role\GenericRole('guest');
$acl = new Yal\Acl\Acl();
var_dump($acl->addRole($roleGuest));
var_dump($acl);
?>
