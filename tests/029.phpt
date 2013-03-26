--TEST--
testResourceInherits

Check for Yal\Acl\Acl::inheritsResource(
                Resource\ResourceInterface|string    $resource
                Resource\ResourceInterface|string    inherit
                bool                                 $onlyParent )
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;

$acl = new Acl();
$resourceCity = new Resource\GenericResource('city');
$resourceBuilding = new Resource\GenericResource('building');
$resourceRoom = new Resource\GenericResource('room');

$acl->addResource($resourceCity)
    ->addResource($resourceBuilding, $resourceCity->getResourceId())
    ->addResource($resourceRoom, $resourceBuilding);

var_dump($acl->inheritsResource($resourceBuilding, $resourceCity, true));       //bool(true)
var_dump($acl->inheritsResource($resourceRoom, $resourceBuilding, true));       //bool(true)
var_dump($acl->inheritsResource($resourceRoom, $resourceCity));                 //bool(true)
var_dump($acl->inheritsResource($resourceCity, $resourceBuilding));             //bool(false)
var_dump($acl->inheritsResource($resourceBuilding, $resourceRoom));             //bool(false)
var_dump($acl->inheritsResource($resourceCity, $resourceRoom));                 //bool(false)

?>
--EXPECTF--
bool(true)
bool(true)
bool(true)
bool(false)
bool(false)
bool(false)