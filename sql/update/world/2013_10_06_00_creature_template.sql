-- Grim Batol
-- Crimsonborne Guardian <Servant of Deathwing>
UPDATE `creature_template` SET `ScriptName`='mob_gardien_de_la_nuee_cramoisie' WHERE `entry`='39381';
UPDATE `creature_template` SET `ScriptName`='mob_brise_tempete_du_crepuscule' WHERE `entry`='39854';
UPDATE `creature_template` SET `ScriptName`='mob_esprit_de_leau_asservi' WHERE `entry`='39961';
UPDATE `creature_template` SET `ScriptName`='mob_elementaire_de_roche_asservi' WHERE `entry`='39900';
UPDATE `creature_template` SET `ScriptName`='mob_sculpte_terre_du_crepuscule' WHERE `entry`='39890';
UPDATE `creature_template` SET `ScriptName`='mob_chercheflamme_rehausse' WHERE `entry`='39415';
UPDATE `creature_template` SET `ScriptName`='mob_marche_vent_rehausse' WHERE `entry`='39414';
UPDATE `creature_template` SET `ScriptName`='mob_brute_gronn_asservie' WHERE `entry`='40166';
UPDATE `creature_template` SET `ScriptName`='mob_esprit_du_tonnerre_asservie' WHERE `entry`='40269';
UPDATE `creature_template` SET `ScriptName`='mob_grippe_feu_du_crepuscule' WHERE `entry`='39870';
UPDATE `creature_template` SET `ScriptName`='mob_braise_ardente_asservie' WHERE `entry`='39892';
UPDATE `creature_template` SET `ScriptName`='mob_habitant_trogg' WHERE `entry`='39450';

-- NPC Coldridge Defender
UPDATE `creature_template` SET `ScriptName`='npc_coldridge_defender' WHERE `entry`='37177';

-- The Bastion of Twilight
-- Feludius <Ascendant Lord>
UPDATE `creature_template` SET `ScriptName`='boss_feludius' WHERE `entry`='43687';
-- Ignacious <Ascendant Lord>
UPDATE `creature_template` SET `ScriptName`='boss_ignacious' WHERE `entry`='43686';
-- Arion <Ascendant Lord>
UPDATE `creature_template` SET `ScriptName`='boss_arion' WHERE `entry`='43688';
-- Terrastra <Ascendant Lord>
UPDATE `creature_template` SET `ScriptName`='boss_terrastra' WHERE `entry`='43689';
-- Elementium Monstrosity
UPDATE `creature_template` SET `ScriptName`='boss_elementium_monstrosity' WHERE `entry`='43735';
-- Heart of Ice
DELETE FROM `spell_script_names` WHERE `spell_id` = 82665;
INSERT INTO `spell_script_names` VALUES ('82665', 'spell_heart_of_ice');

-- Kezhan
UPDATE `creature_template` SET `ScriptName`='npc_original_hot_rod' WHERE `entry`='34840';
