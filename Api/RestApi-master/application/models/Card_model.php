<?php

class Card_model extends CI_model
{
  function get_card($id){
    $this->db->select('*');
    $this->db->from('card');
    if($id !== NULL) {
      $this->db->where('idcard',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_card($add_data){
    $this->db->insert('card',$add_data);
    if($this->db->insert_id()!==NULL){
      return $this->db->insert_id(); 
    }
    else {
      return FALSE;
    }  
  }
  function update_card($id, $update_data){
    $this->db->where('idcard',$id);
    $this->db->update('card',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }

  function delete_card($id){
    $this->db->where('idcard',$id);
    $this->db->delete('card');
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }


}