-- Delete Guild Vendor
-- Stormwind City
DELETE FROM `creature` WHERE `id`=46602;
-- The Exodar
DELETE FROM `creature` WHERE `id`=51501;
-- Ironforge
DELETE FROM `creature` WHERE `id`=51495;
-- Darnassus
DELETE FROM `creature` WHERE `id`=51504;
-- Orgrimmar
DELETE FROM `creature` WHERE `id`=46572;

-- Undercity
DELETE FROM `creature` WHERE `id`=51496;
-- Silvermoon City
DELETE FROM `creature` WHERE `id`=51502;
-- Thunder Bluff
DELETE FROM `creature` WHERE `id`=51503;

-- Shattrath City
DELETE FROM `creature` WHERE `id`=52268;
-- Dalaran
DELETE FROM `creature` WHERE `id`=51512;

-- Error vendor
-- Firelands
DELETE FROM `creature` WHERE `id`=54402;
-- Stormwind
DELETE FROM `creature` WHERE `id`=60002;
DELETE FROM `creature` WHERE `id`=54661;
DELETE FROM `creature` WHERE `id`=51254;
DELETE FROM `creature` WHERE `id`=52028;
INSERT INTO `creature` (`guid`,`id`,`map`,`zone`,`area`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(1409000, 52028, 0, 1519, 1519, 1, 3969, 0, 0, -8808.23, 350.682, 107.049, 4.65195, 300, 0, 0, 1830, 5013, 0, 0, 0, 0);
DELETE FROM `creature` WHERE `id`=52546;
DELETE FROM `creature` WHERE `id`=51256;

-- Orgimmar
DELETE FROM `creature` WHERE `id`=60001;
DELETE FROM `creature` WHERE `id`=46593;
DELETE FROM `creature` WHERE `id`=52549;
DELETE FROM `creature` WHERE `id`=54658;
DELETE FROM `creature` WHERE `id`=54659;



-- Dungeon/Raid disables
DELETE FROM `creature` WHERE `id`=111222;
-- DELETE FROM `gameobject` WHERE `guid`=11363;
DELETE FROM `disables` WHERE `entry` IN (36,33,645,938,670,644,940,755,725,657,643,939,568,757,669,967,720,671,754);
INSERT INTO `disables` VALUES ('2', '36', '2', '', '', 'Dungeon: The Deadmines');
INSERT INTO `disables` VALUES ('2', '33', '2', '', '', 'Dungeon: Shadowfang Keep');
INSERT INTO `disables` VALUES ('2', '645', '3', '', '', 'Dungeon: Blackrock Caverns');
INSERT INTO `disables` VALUES ('2', '938', '3', '', '', 'Dungeon: End Time');
INSERT INTO `disables` VALUES ('2', '670', '3', '', '', 'Dungeon: Grim Batol');
INSERT INTO `disables` VALUES ('2', '644', '3', '', '', 'Dungeon: Halls of Origination');
INSERT INTO `disables` VALUES ('2', '940', '3', '', '', 'Dungeon: Hour of Twilight');
INSERT INTO `disables` VALUES ('2', '755', '3', '', '', 'Dungeon: Lost City of the Tolvir');
INSERT INTO `disables` VALUES ('2', '725', '3', '', '', 'Dungeon: The Stonecore');
INSERT INTO `disables` VALUES ('2', '657', '3', '', '', 'Dungeon: The Vortex Pinnacle');
INSERT INTO `disables` VALUES ('2', '643', '3', '', '', 'Dungeon: Throne of the Tides');
INSERT INTO `disables` VALUES ('2', '939', '3', '', '', 'Dungeon: Well of Eternity');
INSERT INTO `disables` VALUES ('2', '568', '3', '', '', 'Dungeon: Zul Aman');
INSERT INTO `disables` VALUES ('2', '859', '3', '', '', 'Dungeon: Zul Gurub');
INSERT INTO `disables` VALUES ('2', '757', '15', '', '', 'Raid: Baradin Hold');
INSERT INTO `disables` VALUES ('2', '669', '15', '', '', 'Raid: Blackwing Descent');
INSERT INTO `disables` VALUES ('2', '967', '15', '', '', 'Raid: Dragon Soul');
INSERT INTO `disables` VALUES ('2', '720', '15', '', '', 'Raid: Firelands');
INSERT INTO `disables` VALUES ('2', '671', '15', '', '', 'Raid: The Bastion of Twilight');
INSERT INTO `disables` VALUES ('2', '754', '15', '', '', 'Raid: Throne of the Four Winds');

-- Portal Worgen Start Zone
DELETE FROM `gameobject` WHERE `id`=56782;

