<?php

/**
 * @file
 * Admin form for Advanced Page Expiration module
 */

/**
 * Administrative settings form.
 */
function ape_admin_settings($form, &$form_state) {

  $form['page_caching'] = array(
    '#type' => 'fieldset',
    '#title' => t('General page caching'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $cache = variable_get('cache', 0);
  $form['page_caching']['cache'] = array(
    '#type' => 'checkbox',
    '#title' => t('Cache pages for anonymous users'),
    '#default_value' => $cache,
    '#weight' => -2,
  );

  $period = drupal_map_assoc(
    array(
      60,
      180,
      300,
      600,
      900,
      1800,
      2700,
      3600,
      10800,
      21600,
      32400,
      43200,
      86400,
      604800,
      2592000,
      31536000,
    ),
    'format_interval'
  );
  $form['page_caching']['ape_global_lifetime'] = array(
    '#type' => 'select',
    '#title' => t('Global page expiration'),
    '#options' => $period,
    '#default_value' => variable_get('ape_global_lifetime', 0),
    '#description' => t('The standard expiration lifetime for cached pages. Ideally this is set as long as possible.'),
  );

  $form['page_caching_exceptions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Page caching exceptions'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['page_caching_exceptions']['ape_exceptions_lifetime'] = array(
    '#type' => 'select',
    '#title' => t('Expiration length for exceptions'),
    '#options' => $period,
    '#default_value' => variable_get('ape_exceptions_lifetime', 0),
    '#description' => t('A secondary page expiration lifetime. Useful for pages that should refresh at a different rate than most pages, such as a short interval like 5 minutes.'),
  );
  $form['page_caching_exceptions']['ape_exceptions'] = array(
    '#type' => 'textarea',
    '#title' => t('Page expiration exceptions'),
    '#default_value' => variable_get('ape_exceptions', ''),
    '#width' => 40,
    '#height' => 10,
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );
  $form['page_caching_exceptions']['ape_exclusions'] = array(
    '#type' => 'textarea',
    '#title' => t('Pages to exclude from caching'),
    '#default_value' => variable_get('ape_exclusions', ''),
    '#width' => 40,
    '#height' => 5,
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );

  $form['server_codes'] = array(
    '#type' => 'fieldset',
    '#title' => t('Server response caching'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['server_codes']['ape_301_lifetime'] = array(
    '#type' => 'select',
    '#title' => t('301 Redirects Expiration'),
    '#options' => $period,
    '#default_value' => variable_get('ape_301_lifetime', 0),
    '#description' => t('Set a cache lifetime for all 301 redirects.'),
  );
  $form['server_codes']['ape_302_lifetime'] = array(
    '#type' => 'select',
    '#title' => t('302 Redirects Expiration'),
    '#options' => $period,
    '#default_value' => variable_get('ape_302_lifetime', 0),
    '#description' => t('Set a cache lifetime for all 302 redirects.'),
  );

  return system_settings_form($form);
}
