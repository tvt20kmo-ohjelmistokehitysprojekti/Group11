<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Login extends CI_Controller {
    public function index(){
        $this->load->model('Login_model');
        $idcard=$this->input->get('idcard');
        $plaintext_pinCode=$this->input->get('pinCode');
        $encrypted_pinCode=$this->Login_model->check_login($idcard);

        if($encrypted_pinCode==$plaintext_pinCode){
          $result=true;
        }
        else{
          $result=false;
        }
        echo json_encode($result);
    }
}