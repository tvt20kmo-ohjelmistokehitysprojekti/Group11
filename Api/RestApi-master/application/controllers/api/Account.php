<?php

defined('BASEPATH') OR exit('No direct script access allowed');

require APPPATH . 'libraries/REST_Controller.php';

class Account extends REST_Controller {

    function __construct()
    {
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        parent::__construct();

        $this->load->model('Account_model');
    }

    public function index_get()
    { 

        $id = $this->get('id');

        if ($id === NULL)
        {
            $account=$this->Account_model->get_account(NULL);
            if ($account)
            {
                $this->response($account, REST_Controller::HTTP_OK);
            }
            else
            {
                $this->response([
                    'status' => FALSE,
                    'message' => 'No account were found'
                ], REST_Controller::HTTP_NOT_FOUND);
            }
        }

        else {
            if ($id <= 0)
            {
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST);
            }

            $account=$this->Account_model->get_account($id);
            if (!empty($account))
            {
                $this->set_response($account, REST_Controller::HTTP_OK);
            }
            else
            {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'account could not be found'
                ], REST_Controller::HTTP_NOT_FOUND);
            }
        }

    }

    public function index_post()
    {
        $add_data=array(
          'balance'=>$this->post('balance'),
          'card_idcard'=>$this->post('card_idcard')
        );
        $insert_id=$this->Account_model->add_account($add_data);
        if($insert_id)
        {
            $message = [
                'idcard' => $insert_id,
                'balance'=>$this->post('balance'),
                'card_idcard'=>$this->post('card_idcard'),
                'message' => 'Added a resource'
            ];
            $this->set_response($message, REST_Controller::HTTP_CREATED);
        }
        else
        {
            $this->response([
                'status' => FALSE,
                'message' => 'Can not add data'
            ], REST_Controller::HTTP_CONFLICT);
        }

    }
    public function index_put()
    {
        $id=$this->get('id');
        $update_data=array(
          'balance'=>$this->post('balance'),
          'card_idcard'=>$this->post('card_idcard')
        );
        $result=$this->Account_model->update_account($id, $update_data);

        if($result)
        {
            $message = [
                'idcard' => $id,
                'balance'=>$this->post('balance'),
                'card_idcard'=>$this->post('card_idcard'),
                'message' => 'Updates a resource'
            ];

            $this->set_response($message, REST_Controller::HTTP_CREATED);
        }
        else 
        {
            $this->response([
                'status' => FALSE,
                'message' => 'Can not update data'
            ], REST_Controller::HTTP_CONFLICT);
        }
    }

    public function index_delete()
    {
        $id = $this->get('id');

        if ($id <= 0)
        {
            $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST);
        }
        $result=$this->Account_model->delete_account($id);
        if ($result)
        {
          $message = [
              'idcard' => $id,
              'message' => 'Deleted the resource'
          ];
          $this->set_response($message, REST_Controller::HTTP_OK);
        }
        else
        {
            $this->response([
                'status' => FALSE,
                'message' => 'Can not delete data'
            ], REST_Controller::HTTP_CONFLICT);
        }
    }

    public function withdraw_post(){
        $this->load->model('Account_model');
        $idkortti=$this->post('idkortti');
        $amount=$this->post('amount');
        $result=$this->Account_model->withdraw_money($idkortti, $amount);

        if($result>0){
          $respond=true;
        }
        else{
          $respond=false;
        }
        echo json_encode($result);
    }
}
