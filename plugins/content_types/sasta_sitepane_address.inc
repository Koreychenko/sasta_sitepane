<?php
 $plugin = array(
  'single' => TRUE,
  'title' => t('Address pane'),
  'description' => t('Show a site address'),
  'category' => t('Sasta'),
  'render callback' => 'sasta_sitepane_address_render',
  'defaults' => array(
    'show' => 'list',
  )
 );


function sasta_sitepane_address_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $block->title = '';

  $block->content = '<i class="fa fa-map-marker">&nbsp;</i><div class="item-list">'.variable_get('sasta_sitepane_address','').'</div>';

  return $block;
}
