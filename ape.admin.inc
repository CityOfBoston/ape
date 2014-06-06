<?php

/*
 * Administrative settings form
 */
function ape_admin_settings($form, &$form_state) {
  $period = drupal_map_assoc(array(0, 60, 180, 300, 600, 900, 1800, 2700, 3600, 10800, 21600, 32400, 43200, 86400, 604800, 2592000, 31536000), 'format_interval');
  $form['ape_global_lifetime'] = array(
    '#type' => 'select',
    '#title' => t('Global Page Expiration'),
    '#options' => $period,
    '#default_value' => variable_get('ape_global_expiration', 0),
    '#description' => t('The standard expiration lifetime for cached pages.'),
  );
  $form['ape_exceptions_lifetime'] = array(
    '#type' => 'select',
    '#title' => t('Global Page Expiration'),
    '#options' => $period,
    '#default_value' => variable_get('ape_exceptions_lifetime', 0),
    '#description' => t('A secondary page expiration lifetime. Useful for pages that should refresh at a different rate than most pages.'),
  );
  $form['ape_exceptions'] = array(
    '#type' => 'textarea',
    '#title' => t('Page Expiration Exceptions'),
    '#default_value' => variable_get('ape_exceptions', ''),
    '#width' => 40,
    '#height' => 10,
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );
  $form['ape_exclusions'] = array(
    '#type' => 'textarea',
    '#title' => t('Pages to exclude from caching'),
    '#default_value' => variable_get('ape_exclusions', ''),
    '#width' => 40,
    '#height' => 5,
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );

  return system_settings_form($form);
}