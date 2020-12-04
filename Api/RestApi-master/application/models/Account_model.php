<?php

class Account_model extends CI_model
{
  function get_account($id){
    $this->db->select('*');
    $this->db->from('account');
    if($id !== NULL) {
      $this->db->where('card_idcard',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_account($add_data){
    $this->db->insert('account',$add_data);
    if($this->db->insert_id()!==NULL){
      return $this->db->insert_id(); 
    }
    else {
      return FALSE;
    }  
  }
  function update_account($id, $update_data){
    $this->db->query('idaccount',$id);
    $this->db->update('account',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }

  function delete_account($id){
    $this->db->where('idaccount',$id);
    $this->db->delete('account');
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }
  function withdraw_money($idkortti, $amount){
    $call_procedure="CALL withdraw(?,?)";
    $data=array('idkortti'=>$idkortti, 'amount'=>$amount);
    $this->db->query($call_procedure, $data);
    
    return $this->db->affected_rows();
  }
}
