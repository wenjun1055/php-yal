--TEST--
Yal\Acl\Acl::removeResource(Resource\ResourceInterface|string $resource)
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;

$acl = new Acl();
$resourceCity = new Resource\GenericResource('city');

$acl->addResource($resourceCity)
    ->removeResource($resourceCity);
    
var_dump($acl->hasResource(resourceCity));  //bool(false)
?>
--EXPECTF--
bool(false)