-- Blackrock Caverns
-- Rom'ogg Bonecrusher
UPDATE `creature_template` SET `maxlevel`=87 WHERE `entry`=39665;
DELETE FROM `creature_loot_template` WHERE (`entry`=39665);
INSERT INTO `creature_loot_template` VALUES 
(39665, 55777, 26, 1, 0, 1, 1),
(39665, 55776, 22, 1, 0, 1, 1),
(39665, 55278, 16, 1, 0, 1, 1),
(39665, 55778, 17, 1, 0, 1, 1),
(39665, 55279, 11, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid`=39666 WHERE `entry`=39666;
DELETE FROM `creature_loot_template` WHERE (`entry`=39666);
INSERT INTO `creature_loot_template` VALUES 
(39666, 56313, 20, 1, 0, 1, 1),
(39666, 56314, 19, 1, 0, 1, 1),
(39666, 56311, 19, 1, 0, 1, 1),
(39666, 56310, 19, 1, 0, 1, 1),
(39666, 56312, 19, 1, 0, 1, 1);
-- Corla, Herald of Twilight
UPDATE `creature_template` SET `Health_mod`=21.22, `lootid`=39679 WHERE `entry`=39679;
DELETE FROM `creature_loot_template` WHERE (`entry`=39679);
INSERT INTO `creature_loot_template` VALUES 
(39679, 21524, 14, 1, 0, 1, 1),
(39679, 22206, 4, 1, 0, 1, 1),
(39679, 55267, 23, 1, 0, 1, 1),
(39679, 55266, 23, 1, 0, 1, 1),
(39679, 55263, 17, 1, 0, 1, 1),
(39679, 55265, 17, 1, 0, 1, 1),
(39679, 55264, 12, 1, 0, 1, 1);
UPDATE `creature_template` SET `Health_mod`=71.22, `lootid`=39680 WHERE `entry`=39680;
DELETE FROM `creature_loot_template` WHERE (`entry`=39680);
INSERT INTO `creature_loot_template` VALUES 
(39680, 56297, 19, 1, 0, 1, 1),
(39680, 56296, 18, 1, 0, 1, 1),
(39680, 56295, 20, 1, 0, 1, 1),
(39680, 56298, 19, 1, 0, 1, 1),
(39680, 56299, 19, 1, 0, 1, 1);
-- Karsh Steelbender <Twilight Armorer>
UPDATE `creature_template` SET `lootid`=39698 WHERE `entry`=39698;
DELETE FROM `creature_loot_template` WHERE (`entry`=39698);
INSERT INTO `creature_loot_template` VALUES 
(39698, 55268, 21, 1, 0, 1, 1),
(39698, 55271, 21, 1, 0, 1, 1),
(39698, 55272, 21, 1, 0, 1, 1),
(39698, 55270, 15, 1, 0, 1, 1),
(39698, 55269, 14, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid`=39699 WHERE `entry`=39699;
DELETE FROM `creature_loot_template` WHERE (`entry`=39699);
INSERT INTO `creature_loot_template` VALUES 
(39699, 56300, 20, 1, 0, 1, 1),
(39699, 56301, 19, 1, 0, 1, 1),
(39699, 56304, 19, 1, 0, 1, 1),
(39699, 56303, 19, 1, 0, 1, 1),
(39699, 56302, 19, 1, 0, 1, 1);
-- Beauty
UPDATE `creature_template` SET `lootid`=39700 WHERE `entry`=39700;
DELETE FROM `creature_loot_template` WHERE (`entry`=39700);
INSERT INTO `creature_loot_template` VALUES 
(39700, 55277, 27, 1, 0, 1, 1),
(39700, 55273, 18, 1, 0, 1, 1),
(39700, 55276, 18, 1, 0, 1, 1),
(39700, 55275, 17, 1, 0, 1, 1),
(39700, 55274, 12, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid`=39701 WHERE `entry`=39701;
DELETE FROM `creature_loot_template` WHERE (`entry`=39701);
INSERT INTO `creature_loot_template` VALUES 
(39701, 56308, 19, 1, 0, 1, 1),
(39701, 56305, 19, 1, 0, 1, 1),
(39701, 56307, 19, 1, 0, 1, 1),
(39701, 56309, 19, 1, 0, 1, 1),
(39701, 56306, 19, 1, 0, 1, 1);
-- Ascendant Lord Obsidius
UPDATE `creature_template` SET `lootid`=39705 WHERE `entry`=39705;
DELETE FROM `creature_loot_template` WHERE (`entry`=39705);
INSERT INTO `creature_loot_template` VALUES 
(39705, 52078, 39, 1, 0, 1, 1),
(39705, 55787, 27, 1, 0, 1, 1),
(39705, 55782, 23, 1, 0, 1, 1),
(39705, 55788, 22, 1, 0, 1, 1),
(39705, 55780, 21, 1, 0, 1, 1),
(39705, 55781, 16, 1, 0, 1, 1),
(39705, 55779, 16, 1, 0, 1, 1),
(39705, 55784, 14, 1, 0, 1, 1),
(39705, 55786, 14, 1, 0, 1, 1),
(39705, 55785, 14, 1, 0, 1, 1),
(39705, 71715, 0.4, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid`=39706 WHERE `entry`=39706;
DELETE FROM `creature_loot_template` WHERE (`entry`=39706);
INSERT INTO `creature_loot_template` VALUES 
(39706, 56320, 19, 1, 0, 1, 1),
(39706, 56317, 18, 1, 0, 1, 1),
(39706, 56319, 19, 1, 0, 1, 1),
(39706, 56323, 18, 1, 0, 1, 1),
(39706, 56322, 19, 1, 0, 1, 1),
(39706, 56324, 18, 1, 0, 1, 1),
(39706, 56318, 19, 1, 0, 1, 1),
(39706, 56315, 19, 1, 0, 1, 1),
(39706, 56321, 19, 1, 0, 1, 1);
-- Trash
UPDATE `creature_template` SET `Health_mod`=5 WHERE `entry`=39708;
UPDATE `creature_template` SET `Health_mod`=13 WHERE `entry`=39709;
UPDATE `creature_template` SET `Health_mod`=5 WHERE `entry`=39978;
UPDATE `creature_template` SET `Health_mod`=13 WHERE `entry`=39979;
UPDATE `creature_template` SET `Health_mod`=5 WHERE `entry`=39980;
UPDATE `creature_template` SET `Health_mod`=13 WHERE `entry`=39981;
UPDATE `creature_template` SET `Health_mod`=5 WHERE `entry`=39982;
UPDATE `creature_template` SET `Health_mod`=13 WHERE `entry`=39983;
UPDATE `creature_template` SET `Health_mod`=12 WHERE `entry`=39987;
UPDATE `creature_template` SET `Health_mod`=15 WHERE `entry`=39988;
UPDATE `creature_template` SET `Health_mod`=5, `difficulty_entry_1`=39991, `ScriptName`='' WHERE `entry`=39990;
UPDATE `creature_template` SET `Health_mod`=13, `lootid`=39991 WHERE `entry`=39991;
UPDATE `creature_template` SET `Health_mod`=8 WHERE `entry`=39994;
UPDATE `creature_template` SET `Health_mod`=13 WHERE `entry`=39995;
UPDATE `creature_template` SET `Health_mod`=1, `difficulty_entry_1`=40085 WHERE `entry`=40084;
UPDATE `creature_template` SET `Health_mod`=2 WHERE `entry`=40085;
UPDATE `creature_template` SET `Health_mod`=7 WHERE `entry`=40817;
UPDATE `creature_template` SET `Health_mod`=16 WHERE `entry`=40818;
UPDATE `creature_template` SET `Health_mod`=4 WHERE `entry`=50284;
UPDATE `creature_template` SET `Health_mod`=8 WHERE `entry`=50285;
