<?php
/**
 * La configuration de base de votre installation WordPress.
 *
 * Ce fichier est utilisé par le script de création de wp-config.php pendant
 * le processus d’installation. Vous n’avez pas à utiliser le site web, vous
 * pouvez simplement renommer ce fichier en « wp-config.php » et remplir les
 * valeurs.
 *
 * Ce fichier contient les réglages de configuration suivants :
 *
 * Réglages MySQL
 * Préfixe de table
 * Clés secrètes
 * Langue utilisée
 * ABSPATH
 *
 * @link https://fr.wordpress.org/support/article/editing-wp-config-php/.
 *
 * @package WordPress
 */

// ** Réglages MySQL - Votre hébergeur doit vous fournir ces informations. ** //
/** Nom de la base de données de WordPress. */
define( 'DB_NAME', 'wordpress' );

/** Utilisateur de la base de données MySQL. */
define( 'DB_USER', 'root' );

/** Mot de passe de la base de données MySQL. */
define( 'DB_PASSWORD', 'admin' );

/** Adresse de l’hébergement MySQL. */
define( 'DB_HOST', 'localhost' );

/** Jeu de caractères à utiliser par la base de données lors de la création des tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/**
 * Type de collation de la base de données.
 * N’y touchez que si vous savez ce que vous faites.
 */
define( 'DB_COLLATE', '' );

/**#@+
 * Clés uniques d’authentification et salage.
 *
 * Remplacez les valeurs par défaut par des phrases uniques !
 * Vous pouvez générer des phrases aléatoires en utilisant
 * {@link https://api.wordpress.org/secret-key/1.1/salt/ le service de clés secrètes de WordPress.org}.
 * Vous pouvez modifier ces phrases à n’importe quel moment, afin d’invalider tous les cookies existants.
 * Cela forcera également tous les utilisateurs à se reconnecter.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'G=u0%L4Uige:Q-.dpzAtTnW4}9u/d|YYWBw=J,W;lw>[&Hfz%DD3dTckaCTH<lLQ' );
define( 'SECURE_AUTH_KEY',  'aDSyY]L@#+BL4B#ex<A.3x_>X:  ?tu2chLJSw%2#M0py0_D0<`wSu)R)u#O30z)' );
define( 'LOGGED_IN_KEY',    'U_2^TFKzsqp7[c^w3F8`z0Z*TBo|1J&eC^rcn2aPh~K{$%QgJgmaJsRZ-zgNf9Xl' );
define( 'NONCE_KEY',        'jM*}+Ul!hn$/$qDpQl4GIpw{maQ|jPF*lp3(<$O,!*K:HD!wjhV8O:JcXXVu1W`_' );
define( 'AUTH_SALT',        'wKBEz!}[|.dL_Lh02UjQbhF<u`9A!#Lj:KlRDL Q(=e@2cF2TU`1cMVTtlryOE[_' );
define( 'SECURE_AUTH_SALT', '}d[FF1DocW2`RPPG|1.nj*<%wY_5i@,*$>VDd_fD3@!49)0{q|c[dO=U 3IY)V}4' );
define( 'LOGGED_IN_SALT',   '%_K))t e=I2Rn{AEu5m~fq}N`];ZqCXnla<j?<n5J)mTOa?dhOg#K=1Jb](7r,o3' );
define( 'NONCE_SALT',       'ZX@WjNbI%H!`z*Fr^1d`QTnLK/55iN$=,#gptks2_c@9PkpK@az2r)~WCY7,)v{g' );
/**#@-*/

/**
 * Préfixe de base de données pour les tables de WordPress.
 *
 * Vous pouvez installer plusieurs WordPress sur une seule base de données
 * si vous leur donnez chacune un préfixe unique.
 * N’utilisez que des chiffres, des lettres non-accentuées, et des caractères soulignés !
 */
$table_prefix = 'wp_';

/**
 * Pour les développeurs : le mode déboguage de WordPress.
 *
 * En passant la valeur suivante à "true", vous activez l’affichage des
 * notifications d’erreurs pendant vos essais.
 * Il est fortement recommandé que les développeurs d’extensions et
 * de thèmes se servent de WP_DEBUG dans leur environnement de
 * développement.
 *
 * Pour plus d’information sur les autres constantes qui peuvent être utilisées
 * pour le déboguage, rendez-vous sur le Codex.
 *
 * @link https://fr.wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* C’est tout, ne touchez pas à ce qui suit ! Bonne publication. */

/** Chemin absolu vers le dossier de WordPress. */
if ( ! defined( 'ABSPATH' ) )
  define( 'ABSPATH', dirname( __FILE__ ) . '/' );

/** Réglage des variables de WordPress et de ses fichiers inclus. */
require_once( ABSPATH . 'wp-settings.php' );

