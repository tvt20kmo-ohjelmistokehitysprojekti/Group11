<?php

class Login_model extends CI_model
{
  function check_login($idcard){
    $this->db->select('pinCode');
    $this->db->from('card');
    $this->db->where('idcard',$idcard);
    return $this->db->get()->row('pinCode');
  }

}