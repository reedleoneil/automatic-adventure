BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS `cars` (
	`carId`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	`brand`	TEXT,
	`model`	TEXT,
	`ownerFirstName`	TEXT,
	`ownerMiddleName`	TEXT,
	`ownerLastName`	TEXT,
	`ownerContactNumber`	TEXT,
	`ownerRFID`	TEXT
);
INSERT INTO `cars` (carId,brand,model,ownerFirstName,ownerMiddleName,ownerLastName,ownerContactNumber,ownerRFID) VALUES (1,'Toyota','Hilux','Reed Leoneil','Pineda','Pascual','09163624205','alskdjfasjdf'),
 (2,'Honda','Civic','Ed Byncent','Pineda','Pascual','09163624205','asdfasdfasdf');
COMMIT;
