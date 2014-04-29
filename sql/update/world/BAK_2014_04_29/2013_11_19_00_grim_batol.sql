-- Grim Batol
-- General Umbriss
UPDATE `creature_template` SET `Health_mod`=32, `difficulty_entry_1`=48337, `lootid`=39625 WHERE `entry`=39625;
UPDATE `creature_template` SET `mindmg`=3700, `maxdmg`=4500, `attackpower`=2000, `dmg_multiplier`=5 WHERE `entry`=39625;
DELETE FROM `creature_loot_template` WHERE (`entry`=39625);
INSERT INTO `creature_loot_template` VALUES 
(39625, 56116, 27, 1, 0, 1, 1),
(39625, 56115, 24, 1, 0, 1, 1),
(39625, 56112, 18, 1, 0, 1, 1),
(39625, 56113, 12, 1, 0, 1, 1),
(39625, 56114, 12, 1, 0, 1, 1);
UPDATE `creature_template` SET `Health_mod`=65, `difficulty_entry_1`=0, `lootid`=48337 WHERE `entry`=48337;
UPDATE `creature_template` SET `mindmg`=3700, `maxdmg`=4500, `attackpower`=2000, `dmg_multiplier`=7 WHERE `entry`=48337;
DELETE FROM `creature_loot_template` WHERE (`entry`=48337);
INSERT INTO `creature_loot_template` VALUES 
(48337, 56443, 20, 1, 0, 1, 1),
(48337, 56442, 19, 1, 0, 1, 1),
(48337, 56441, 19, 1, 0, 1, 1),
(48337, 56440, 19, 1, 0, 1, 1),
(48337, 56444, 19, 1, 0, 1, 1);
-- Forgemaster Throngus
UPDATE `creature_template` SET `Health_mod`=32, `difficulty_entry_1`=48702, `lootid`=40177 WHERE `entry`=40177;
UPDATE `creature_template` SET `mindmg`=3700, `maxdmg`=4500, `attackpower`=2000, `dmg_multiplier`=5 WHERE `entry`=40177;
DELETE FROM `creature_loot_template` WHERE (`entry`=40177);
INSERT INTO `creature_loot_template` VALUES 
(40177, 56120, 25, 1, 0, 1, 1),
(40177, 56118, 20, 1, 0, 1, 1),
(40177, 56121, 19, 1, 0, 1, 1),
(40177, 56122, 18, 1, 0, 1, 1),
(40177, 56119, 12, 1, 0, 1, 1);
UPDATE `creature_template` SET `Health_mod`=65, `difficulty_entry_1`=0, `lootid`=48702 WHERE `entry`=48702;
UPDATE `creature_template` SET `mindmg`=3700, `maxdmg`=4500, `attackpower`=2000, `dmg_multiplier`=7 WHERE `entry`=48702;
DELETE FROM `creature_loot_template` WHERE (`entry`=48702);
INSERT INTO `creature_loot_template` VALUES 
(48702, 56447, 19, 1, 0, 1, 1),
(48702, 56448, 19, 1, 0, 1, 1),
(48702, 56445, 19, 1, 0, 1, 1),
(48702, 56449, 19, 1, 0, 1, 1),
(48702, 56446, 19, 1, 0, 1, 1);
-- Drahga Shadowburner
UPDATE `creature_template` SET `Health_mod`=32, `difficulty_entry_1`=48784, `lootid`=40319 WHERE `entry`=40319;
UPDATE `creature_template` SET `mindmg`=3700, `maxdmg`=4500, `attackpower`=2000, `dmg_multiplier`=5 WHERE `entry`=40319;
DELETE FROM `creature_loot_template` WHERE (`entry`=40319);
INSERT INTO `creature_loot_template` VALUES 
(40319, 66927, 36, 1, 0, 1, 1),
(40319, 56126, 17, 1, 0, 1, 1),
(40319, 56123, 17, 1, 0, 1, 1),
(40319, 56127, 17, 1, 0, 1, 1),
(40319, 21525, 14, 1, 0, 1, 1),
(40319, 56125, 12, 1, 0, 1, 1),
(40319, 56124, 12, 1, 0, 1, 1),
(40319, 22206, 3, 1, 0, 1, 1);
UPDATE `creature_template` SET `Health_mod`=65, `difficulty_entry_1`=0, `lootid`=48784 WHERE `entry`=48784;
UPDATE `creature_template` SET `mindmg`=3700, `maxdmg`=4500, `attackpower`=2000, `dmg_multiplier`=7 WHERE `entry`=48784;
DELETE FROM `creature_loot_template` WHERE (`entry`=48784);
INSERT INTO `creature_loot_template` VALUES 
(48784, 56452, 18, 1, 0, 1, 1),
(48784, 56451, 18, 1, 0, 1, 1),
(48784, 56450, 17, 1, 0, 1, 1),
(48784, 56453, 17, 1, 0, 1, 1),
(48784, 56454, 17, 1, 0, 1, 1),
(48784, 21525, 14, 1, 0, 1, 1),
(48784, 66927, 36, 1, 0, 1, 1),
(48784, 22206, 3, 1, 0, 1, 1);
-- Erudax
UPDATE `creature_template` SET `Health_mod`=47, `difficulty_entry_1`=48822, `lootid`=40484 WHERE `entry`=40484;
UPDATE `creature_template` SET `mindmg`=3700, `maxdmg`=4500, `attackpower`=2000, `dmg_multiplier`=5 WHERE `entry`=40484;
DELETE FROM `creature_loot_template` WHERE (`entry`=40484);
INSERT INTO `creature_loot_template` VALUES 
(40484, 56137, 25, 1, 0, 1, 1),
(40484, 56131, 24, 1, 0, 1, 1),
(40484, 56138, 22, 1, 0, 1, 1),
(40484, 56132, 21, 1, 0, 1, 1),
(40484, 56129, 17, 1, 0, 1, 1),
(40484, 56136, 17, 1, 0, 1, 1),
(40484, 56133, 17, 1, 0, 1, 1),
(40484, 56130, 16, 1, 0, 1, 1),
(40484, 56128, 15, 1, 0, 1, 1),
(40484, 56135, 11, 1, 0, 1, 1);
UPDATE `creature_template` SET `Health_mod`=95, `difficulty_entry_1`=0, `lootid`=48822 WHERE `entry`=48822;
UPDATE `creature_template` SET `mindmg`=3700, `maxdmg`=4500, `attackpower`=2000, `dmg_multiplier`=7 WHERE `entry`=48822;
DELETE FROM `creature_loot_template` WHERE (`entry`=48822);
INSERT INTO `creature_loot_template` VALUES 
(48822, 52078, 38, 1, 0, 1, 1),
(48822, 56457, 19, 1, 0, 1, 1),
(48822, 56463, 19, 1, 0, 1, 1),
(48822, 56462, 19, 1, 0, 1, 1),
(48822, 56459, 19, 1, 0, 1, 1),
(48822, 56458, 19, 1, 0, 1, 1),
(48822, 56461, 19, 1, 0, 1, 1),
(48822, 56456, 19, 1, 0, 1, 1),
(48822, 56464, 18, 1, 0, 1, 1),
(48822, 56460, 18, 1, 0, 1, 1),
(48822, 56455, 18, 1, 0, 1, 1);
