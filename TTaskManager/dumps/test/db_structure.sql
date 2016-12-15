-- Valentina Studio --
-- MySQL dump --
-- ---------------------------------------------------------


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
-- ---------------------------------------------------------


-- CREATE TABLE "task" -------------------------------------
CREATE TABLE `task` ( 
	`id` Int( 11 ) AUTO_INCREMENT NOT NULL,
	`order_pos` Int( 11 ) NOT NULL DEFAULT '0',
	`name` VarChar( 255 ) NOT NULL DEFAULT '<EMPTY>',
	`parent_id` Int( 11 ) NULL,
	`date_create` DateTime NULL DEFAULT CURRENT_TIMESTAMP,
	`date_last_modified` DateTime NULL ON UPDATE CURRENT_TIMESTAMP,
	`status` Enum( 'open', 'in_box', 'in_progress', 'close', 'cancel' ) NULL DEFAULT 'open',
	`comment` Text NULL,
	`type` Enum( 'category', 'task', 'book', 'smart', 'meeting', 'principle' ) NOT NULL DEFAULT 'task',
	PRIMARY KEY ( `id` ) )
ENGINE = InnoDB
AUTO_INCREMENT = 0;
-- ---------------------------------------------------------


-- CREATE INDEX "parent_id" --------------------------------
CREATE INDEX `parent_id` USING BTREE ON `task`( `parent_id` );
-- ---------------------------------------------------------


-- CREATE LINK "task_ibfk_1" -------------------------------
ALTER TABLE `task`
	ADD CONSTRAINT `task_ibfk_1` FOREIGN KEY ( `parent_id` )
	REFERENCES `task`( `id` )
	ON DELETE No Action
	ON UPDATE No Action;
-- ---------------------------------------------------------


/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
-- ---------------------------------------------------------


