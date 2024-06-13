<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * Localized language
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'wpuser' );

/** Database password */
define( 'DB_PASSWORD', 'password' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',          'FhcF7Z7KF1Qy&/`U@G2lgz/gPnc9Ee5D<e_sZy:~iZRQQ_Oc*hOoF5$TL[0:CheF' );
define( 'SECURE_AUTH_KEY',   'CWO]s+|L?/rA8NQ7^%on7Eu~is_RR,daOzZ5E,a7P!6V2nYZ{967K*G#,DeHnzWb' );
define( 'LOGGED_IN_KEY',     'd-z>vY<iKdS?`R/R`T`%f9(z<`>lF*Qkl5dL-gJYFT.TS<5wVhHvhMbE!C.q%+8q' );
define( 'NONCE_KEY',         'Iy[rS{<4|1M3wzm7hR7(0WLRbwyW@~`n]I495o%e7]~]GR)E#Q]qg[jc&l#2MjKp' );
define( 'AUTH_SALT',         '+*-:E6ImzCJj]!4R8^6_=SphW9~<p7A=xt<1fy^9o{Tw=u_UtU|CYedAzw-1;LC!' );
define( 'SECURE_AUTH_SALT',  'K4%5C+,i[cUNX-rur,Qo-<BTKseO_&5s85NDaQgMgg^lYx:G3vXa<Q.~YawVfEbw' );
define( 'LOGGED_IN_SALT',    'Z7Itok=JTU5:#j_~40>tafqgt4_@9.3pqs@X3=>nl/m=xeb^ @d87QhG!qOpjJ%~' );
define( 'NONCE_SALT',        'K+Xwt(6-!3Iu6%A %DfNEBs;$swoX_Y<%H.:6<1#o&72N 5w-X/k#w`%?!o]Glf#' );
define( 'WP_CACHE_KEY_SALT', 'IE1-jY`sf>lgfWuF/!0o~)8e:/O.Eo?$7)DNvf@TkjJg!}J)gun]k6?/aUG30@a@' );


/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';


/* Add any custom values between this line and the "stop editing" line. */



/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
if ( ! defined( 'WP_DEBUG' ) ) {
	define( 'WP_DEBUG', false );
}

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
