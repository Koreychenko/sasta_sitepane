<?php
 $plugin = array(
  'single' => TRUE,
  'title' => t('Phones pane'),
  'description' => t('Show a site phones'),
  'category' => t('Sasta'),
  'edit form' => 'sasta_sitepane_phones_edit_form',
  'render callback' => 'sasta_sitepane_phones_render',
  'admin info' => 'sasta_sitepane_phones_admin_info',
  'defaults' => array(
    'show' => 'list',
  )
 );

function sasta_sitepane_phones_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = $conf['show'];
    return $block;
  }
}

function sasta_sitepane_phones_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['show'] = array(
    '#title' => t('Phones show style'),
    '#type' => 'select',
    '#default_value' => $conf['show'],
    '#options' => array(
      'list' => t('List'),
      'inline' => t('Inline'),
      ),
    '#required' => FALSE,
  );

   return $form;
}


function sasta_sitepane_phones_edit_form_submit($form, $form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

function sasta_sitepane_phones_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $block->title = '';

  $phones = variable_get('sasta_sitepane_phones',array());

  switch ($conf['show']) {
    case 'list':
      $content = theme('item_list',array(
        'items' => $phones,
        'title' => '',
        'type' => 'ul',
        'attributes' => array('class'=>array('phones')),
        ));
    break;
    case 'inline':
      $content = theme('item_list',array(
        'items' => $phones,
        'title' => '',
        'type' => 'ul',
        'attributes' => array('class'=>array('phones','inline')),
        ));
    break;
  }

  $block->content = $content;

  return $block;
}
