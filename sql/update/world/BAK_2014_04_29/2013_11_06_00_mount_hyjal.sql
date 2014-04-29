DELETE FROM creature WHERE guid=321300;
INSERT INTO `creature` VALUES ('321300', '53014', '1', '616', '5015', '1', '1', '0', '0', '5224.81', '-1234.48', '1375.66', '4.25622', '300', '0', '0', '586810', '0', '2', '0', '0', '0');

DELETE FROM waypoint_data WHERE id=321300;
INSERT INTO `waypoint_data` VALUES ('321300', '1', '5226.8', '-1232.2', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '2', '5227.89', '-1230.41', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '3', '5229.6', '-1228.19', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '4', '5234.5', '-1221.84', '1376.06', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '5', '5238.44', '-1215.78', '1376.94', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '6', '5238.55', '-1212.77', '1376.94', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '7', '5236.55', '-1211.77', '1376.94', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '8', '5234.88', '-1214.17', '1376.9', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '9', '5233.07', '-1216.65', '1376.61', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '10', '5230.93', '-1219.71', '1376.06', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '11', '5229.55', '-1220.94', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '12', '5226.6', '-1221.05', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '13', '5223.1', '-1221.12', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '14', '5221.29', '-1222.77', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '15', '5222.65', '-1225.61', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '16', '5224.37', '-1229.66', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '17', '5225.01', '-1232.35', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '18', '5223.61', '-1234.96', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '19', '5221.64', '-1238.12', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '20', '5222.63', '-1239.24', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '21', '5224.57', '-1236.62', '1375.66', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('321300', '22', '5225.24', '-1234.51', '1375.66', '0', '0', '0', '0', '100', '0', '0');

DELETE FROM creature_equip_template WHERE entry=53014;
INSERT INTO `creature_equip_template` VALUES ('53014', '1', '71355', '0', '0');

DELETE FROM creature_template WHERE entry=53014;
INSERT INTO `creature_template` VALUES ('53014', '0', '0', '0', '0', '0', '38062', '0', '0', '0', 'Leyara', '', '', '0', '85', '85', '3', '0', '7', '7', '0', '1', '1.14286', '1', '1.14286', '1', '1', '311', '404', '0', '312', '1', '2000', '2000', '1', '0', '2048', '0', '0', '0', '0', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '98972', '98078', '98064', '97723', '0', '0', '0', '0', '0', '0', '0', '0', '', '0', '3', '1', '10', '10', '1', '1', '0', '0', '0', '0', '0', '0', '0', '133', '1', '53014', '0', '0', '', '15595');

DELETE FROM creature WHERE guid=321301;
INSERT INTO `creature` VALUES ('321301', '52766', '1', '616', '4861', '1', '1', '0', '0', '4606.14', '-2713.57', '1146.73', '2.0672', '300', '0', '0', '234724', '44540', '0', '0', '0', '0');

DELETE FROM creature_template WHERE entry=52766;
INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 52766, 0, 0, 0, 52816, 0, 11997, 0, 0, 0, "Lylagar", "", "", 0, 85, 85, 3, 91, 91, 2, 1.0, 1.14286, 1.0, 1, 412, 604, 0, 0, 3.1, 2000, 2000, 2, 32768, 0, 0, 0, 0, 0, 0, 412, 604, 0, 1, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98110, 98106, 84867, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", 0, 3, 5.153, 20.0, 1.0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "", "15595");

DELETE FROM `creature_template` WHERE `entry`=52399 LIMIT 1;
INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 52399, 0, 0, 0, 52816, 0, 13031, 0, 0, 0, "Galenges", "The Unbreakable", "", 0, 85, 85, 3, 91, 91, 51, 2.4, 1.42857, 1.0, 1, 524, 633, 0, 0, 2.9, 2000, 2000, 1, 0, 0, 0, 0, 0, 0, 0, 524, 633, 0, 7, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 82615, 82616, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", 0, 3, 22.1, 1.0, 1.0, 0, 0, 0, 0, 0, 0, 0, 152, 1, 0, 0, 0, "", "15595");

DELETE FROM creature WHERE guid=321302;
INSERT INTO `creature` VALUES ('321302', '52399', '1', '616', '4861', '1', '1', '0', '0', '4586.04', '-2664.44', '1132.69', '1.8892', '300', '0', '0', '997577', '0', '0', '0', '0', '0');

DELETE FROM `creature_template` WHERE `entry`=53267 LIMIT 1;
INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 53267, 0, 0, 0, 52816, 52300, 38012, 0, 0, 0, "Andrazor", "Lord of Cinders", "", 0, 86, 86, 3, 7, 7, 0, 1.44444, 1.5873, 1.0, 1, 489, 511, 0, 0, 2.8, 2000, 2000, 4, 32768, 0, 0, 0, 0, 0, 0, 489, 511, 0, 4, 72, 53267, 0, 0, 0, 0, 0, 0, 0, 0, 98711, 100976, 98036, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", 0, 4, 30.6345, 27282.0, 1.0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "", "15595");

DELETE FROM `creature_loot_template` WHERE entry='53267';
INSERT INTO `creature_loot_template` VALUES ('53267', '71376', '97.2', '1', '0', '1', '2');
INSERT INTO `creature_loot_template` VALUES ('53267', '71375', '93.3', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '55440', '0.21', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62063', '0.21', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62064', '0.21', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '55611', '0.18', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '68729', '0.15', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62070', '0.12', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62065', '0.11', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '55422', '0.1', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62066', '0.1', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '55774', '0.08', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62067', '0.08', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62109', '0.08', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62115', '0.08', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '55675', '0.07', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62068', '0.07', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62069', '0.07', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62113', '0.07', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62123', '0.07', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62129', '0.07', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62136', '0.07', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62072', '0.05', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '62120', '0.04', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('53267', '67123', '0.01', '1', '0', '1', '1');
UPDATE `creature_template` SET lootid='53267' WHERE entry='53267';

DELETE FROM creature WHERE id=53267;
INSERT INTO `creature`  VALUES (321303, 53267, 1, 616, 5087, 1, 1, 0, 0, 3630.37, -2304.24, 1110.14, 4.07203, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321304, 53267, 1, 616, 5087, 1, 1, 0, 0, 3704.96, -2276.97, 1139.73, 0.769426, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321305, 53267, 1, 616, 5087, 1, 1, 0, 0, 3738.33, -2246.63, 1147.71, 3.93153, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321306, 53267, 1, 616, 5087, 1, 1, 0, 0, 3648.77, -2267.51, 1106.29, 3.65053, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321307, 53267, 1, 616, 5087, 1, 1, 0, 0, 3630.29, -2325.21, 1111.77, 4.39511, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321308, 53267, 1, 616, 5087, 1, 1, 0, 0, 3610.01, -2364.37, 1113.83, 1.07244, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321309, 53267, 1, 616, 5087, 1, 1, 0, 0, 3706.71, -2249.17, 1140.9, 5.56425, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321310, 53267, 1, 616, 616, 1, 1, 0, 0, 3787.68, -2427.26, 1100.95, 0.425134, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321311, 53267, 1, 616, 616, 1, 1, 0, 0, 3810.94, -2414.07, 1096.21, 0.129083, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321312, 53267, 1, 616, 616, 1, 1, 0, 0, 3818.33, -2454.98, 1079.67, 4.54564, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321313, 53267, 1, 616, 616, 1, 1, 0, 0, 3799.86, -2470.7, 1084.74, 3.88329, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321314, 53267, 1, 616, 616, 1, 1, 0, 0, 3775.37, -2497.55, 1085.23, 3.96357, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321315, 53267, 1, 616, 616, 1, 1, 0, 0, 3750.51, -2522.52, 1086.7, 3.30122, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321316, 53267, 1, 616, 616, 1, 1, 0, 0, 3735.01, -2502.5, 1100.78, 2.31773, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321317, 53267, 1, 616, 616, 1, 1, 0, 0, 3737.46, -2478.1, 1102.5, 1.76075, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321318, 53267, 1, 616, 616, 1, 1, 0, 0, 3727.01, -2468.26, 1130.59, 2.38296, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321319, 53267, 1, 616, 616, 1, 1, 0, 0, 3715.81, -2450.61, 1163.52, 3.31361, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321320, 53267, 1, 616, 616, 1, 1, 0, 0, 3694.23, -2449.51, 1201.37, 3.24837, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321321, 53267, 1, 616, 5087, 1, 1, 0, 0, 3657.51, -2442, 1189.11, 2.88207, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321322, 53267, 1, 616, 5087, 1, 1, 0, 0, 3654.46, -2400.8, 1188.46, 1.60754, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
INSERT INTO `creature`  VALUES (321323, 53267, 1, 616, 5087, 1, 1, 0, 0, 3666.63, -2373.35, 1174.35, 1.61758, 300, 0, 0, 162610, 12774, 0, 0, 0, 0);
