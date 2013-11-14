DELETE FROM `character_inventory` WHERE `item` IN 
(
	SELECT `guid` FROM `item_instance` WHERE `itemEntry` IN (37815,37859,37860)
);
DELETE FROM `item_instance` WHERE `itemEntry` IN (37815,37859,37860);