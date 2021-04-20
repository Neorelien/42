cat << EOF > /srv/www/wp-config.php
<?php
// ** Réglages MySQL - Votre hébergeur doit vous fournir ces informations. ** //
/** Nom de la base de données de WordPress. */
define('DB_NAME', 'wordpress');
/** Utilisateur de la base de données MySQL. */
define('DB_USER', 'wp_user');
/** Mot de passe de la base de données MySQL. */
define('DB_PASSWORD', '$WP_PASS');
/** Adresse de l’hébergement MySQL. */
define('DB_HOST', 'svc-mariadb.default.svc.cluster.local');
/** Jeu de caractères à utiliser par la base de données lors de la création des tables. */
define('DB_CHARSET', 'utf8');
