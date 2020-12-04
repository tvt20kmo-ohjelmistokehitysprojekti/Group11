<?php

class Action_model extends CI_model
{
  function get_action($id){
    $this->db->select('*');
    $this->db->from('action');
    if($id !== NULL) {
      $this->db->where('idaccount',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_action($add_data){
    $this->db->insert('action',$add_data);
    if($this->db->insert_id()!==NULL){
      return $this->db->insert_id(); 
    }
    else {
      return FALSE;
    }  
  }
  function update_action($id, $update_data){
    $this->db->where('idaction',$id);
    $this->db->update('action',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }

  function delete_action($id){
    $this->db->where('idaction',$id);
    $this->db->delete('action');
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }


}